#include "imgmanager.h"
#include <QDebug>
using namespace std;

ImgManager::ImgManager(QLabel *qlabel, QWidget *parent):QWidget(parent)
{
    img_display_region = qlabel;
    img_display_region->setSizePolicy(QSizePolicy::Ignored,QSizePolicy::Ignored); //set size of img area
    img_display_region->setBackgroundRole(QPalette::Dark);                        //set color of background
    img_display_region->setScaledContents(true);                                  //make img adapt to the size of img label

}

void ImgManager::img_display_on_label(const QImage img)
{
    img_display_region->setPixmap(QPixmap::fromImage(img));
}


QImage ImgManager::getImg(const QString &srcPath)
{
    std::string imgPath = srcPath.toStdString();
    imgType = srcPath.section(".",-1);
    if(imgType!="bmp"){
        srcImg= cv::imread(imgPath,cv::IMREAD_COLOR);
    }
    else{
        srcImg= cv::imread(imgPath,cv::IMREAD_GRAYSCALE);
    }
    if(srcImg.empty()){
        qDebug()<<"the path isn't correct";
    }
    else{
//        cv::resize(srcImg, srcImg, cv::Size(0,0),  2., 2., cv::INTER_LINEAR );
        return keepOriginalImage(srcPath);
    }
}


QImage ImgManager::loadImg(const QString &srcPath)
{
    qDebug()<<srcPath;
    std::string imgPath = srcPath.toStdString();
    imgType = srcPath.section(".",-1);

    if(imgType!="bmp"){
        srcImg= cv::imread(imgPath,cv::IMREAD_COLOR);
    }
    else{
        srcImg= cv::imread(imgPath,cv::IMREAD_GRAYSCALE);
    }
    if(srcImg.empty()){
        qDebug()<<"the path isn't correct";}
    else{
        dstImg = srcImg.clone();
        return keepOriginalImage(srcPath);
    }
}

QImage ImgManager::update(const QString &srcPath)
{
    imgType = srcPath.section(".",-1);
    qDebug()<<imgType;
    QImage img;
    if(imgType!="bmp"){
        img = QImage((const unsigned char*)(dstImg.data),dstImg.cols,dstImg.rows,dstImg.step, QImage::Format_BGR888);
    }
    else {
        img = QImage( dstImg.data,
                      dstImg.cols, dstImg.rows,
                      static_cast<int>(dstImg.step),
                      QImage::Format_Grayscale8 );
        /**ref:https://www.taodudu.cc/news/show-1675640.html **/
    }
    return img;
}

QImage ImgManager::keepOriginalImage(const QString &srcPath)
{
    imgType = srcPath.section(".",-1);
    QImage img;
    if(imgType!="bmp"){
        img = QImage((const unsigned char*)(srcImg.data),srcImg.cols,srcImg.rows,srcImg.step,QImage::Format_BGR888);
    }
    else {
        img = QImage( dstImg.data,
                      dstImg.cols, dstImg.rows,
                      static_cast<int>(dstImg.step),
                      QImage::Format_Grayscale8 );
        /**ref:https://www.taodudu.cc/news/show-1675640.html **/
    }
    return img;
}

void ImgManager::on_boxFilter(const int kernel_size)
{
    cv::boxFilter(srcImg,dstImg,-1,cv::Size(kernel_size,kernel_size));
}

void ImgManager::on_blur(const int kernel_seze)
{
    cv::blur(srcImg,dstImg,cv::Size(kernel_seze,kernel_seze));
}

void ImgManager::on_gaussianBlur(const int kernel_size)
{
    cv::GaussianBlur(srcImg,dstImg,cv::Size(kernel_size*2+1,kernel_size*2+1),0,0);
}

void ImgManager::on_medianBlur(const int kernel_size)
{
    cv::medianBlur(srcImg,dstImg,2*kernel_size+1);
}

QImage ImgManager::on_grayscale(const QString &srcPath)
{
    imgType = srcPath.section(".",-1);
    qDebug()<<imgType;
    std::string imgPath = srcPath.toStdString();

    if(imgType!="bmp"){
        srcImg= cv::imread(imgPath,cv::IMREAD_COLOR);
        cv::cvtColor(srcImg,dstImg,cv::COLOR_BGR2GRAY);

    }
    else{
        srcImg= cv::imread(imgPath,cv::IMREAD_GRAYSCALE);
        dstImg = srcImg.clone();
    }
    QString _imgType("bmp");
    return update(_imgType);
}

QImage ImgManager::on_egdeDetection(const QString &srcPath)
{
    // external gradient
    imgType = srcPath.section(".",-1);
    std::string imgPath = srcPath.toStdString();
    if(imgType!="bmp"){
        srcImg= cv::imread(imgPath,cv::IMREAD_COLOR);
        cv::cvtColor(srcImg,dstImg,cv::COLOR_RGB2GRAY);
    }
    else{
        srcImg= cv::imread(imgPath,cv::IMREAD_GRAYSCALE);
        dstImg = srcImg.clone();
    }
    cv::Mat SE = cv::getStructuringElement(cv::MORPH_RECT,cv::Size(5,5));
    cv::Mat temp;
    cv::dilate(dstImg,temp,SE);
    dstImg = temp - dstImg;
    QString _imgType("bmp");
    return update(_imgType);
}

void ImgManager::on_changementSave(const QString &srcPath)
{
    std::string imgPath = srcPath.toStdString();
    qDebug()<<srcPath;
    imgType = srcPath.section("/",-1);
    QString dest="./newfiles/";
    QDir dir;
    if(!dir.exists(dest))
    {
        dir.mkpath(dest);
    }
    cv::imwrite(dest.toStdString()+imgType.toStdString(),dstImg);
    QMessageBox::warning(this,"IMG_SAVED","the current image is saved in ./newfiles.",QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes);
}

void ImgManager::on_imgsSaved2PDF()
{
    std::vector<cv::String> imgFiles;
    Magick::Blob imgsCache;
    QString src="./newfiles/";
    QString dest="./newPDF/";
    QDir dir;
    if(!dir.exists(src))
    {
        QMessageBox::warning(this,"IMG_SAVED2PDF","there is no relavant image to be convert",QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes);
    }
    if(!dir.exists(dest))
    {
       dir.mkpath(dest);
    }
    std::string img_pattern_jpg = src.toStdString()+"*.jpg";
    cv::glob(img_pattern_jpg, imgFiles);
    std::string str_;
    Magick::Image img;
    for(unsigned int i=0; i<imgFiles.size();++i)
        {
//            cv::Mat img = cv::imread(imgFiles[i],cv::IMREAD_COLOR);
//            Magick::Image mgk(img.cols, img.rows, "BGR", Magick::CharPixel, (char *)img.data);
            img.read(imgFiles[i]);
            str_ =dest.toStdString()+to_string(i)+".pdf";
            std::cout<<imgFiles[i]<<"|"<<str_<<std::endl;
            try {
                img.write(str_);
            } catch (exception &error_) {
                std::cout << "exception: " << error_.what() << std::endl;
            }
        }
}

QImage ImgManager::on_Interpolation_zoom(const QString &srcPath, const int factor,const int mode=1)
{
    imgType = srcPath.section(".",-1);
    std::string imgPath = srcPath.toStdString();
    if(imgType!="bmp"){
        srcImg= cv::imread(imgPath,cv::IMREAD_COLOR);
    }
    else{
        srcImg= cv::imread(imgPath,cv::IMREAD_GRAYSCALE);
    }
    dstImg = srcImg.clone();
    if (mode==1){
        cv::resize(srcImg, dstImg, cv::Size(0,0),  factor/10., factor/10., cv::INTER_LINEAR );
    }else if(mode==2){
        cv::resize(srcImg, dstImg, cv::Size(0,0),  factor/10., factor/10., cv::INTER_NEAREST);
    }else{
        cv::resize(srcImg, dstImg, cv::Size(0,0),  factor/10., factor/10., cv::INTER_CUBIC);
    }
    return update(srcPath);
}
