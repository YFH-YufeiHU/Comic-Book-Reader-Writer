#include "mainwindow.h"
#include "./ui_mainwindow.h"

#include <QFileDialog>
#include <QStandardPaths>
#include <QMessageBox>
#include <QFileInfo>
#include <QDebug>
#include <QListWidget>
#include <QtWidgets>
#include <QListWidgetItem>
#include <QIcon>
#include <QAbstractItemView>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),
      ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    tempPath   = "../bin";
    filesModel = new QStringListModel(this);
    imgsModel  = new QFileSystemModel(this);
    imgManager = new ImgManager(ui->label_img);
    zipManager = new ZipManager();
    myBrowserManager = new browserManager();

    ui->horizontalSlider_blur->setRange(0,24);
    ui->horizontalSlider_blur->setValue(0);

    ui->horizontalSlider_box->setRange(0,10);
    ui->horizontalSlider_box->setValue(0);

    ui->horizontalSlider_gaussian->setRange(0,10);
    ui->horizontalSlider_gaussian->setValue(0);

    ui->horizontalSlider_median->setRange(0,10);
    ui->horizontalSlider_median->setValue(0);

    //initial zoom scroll bar
    ui->horizontalScrollBar_for_zoom->setMinimum(1);
    ui->horizontalScrollBar_for_zoom->setMaximum(12);
    ui->horizontalScrollBar_for_zoom->setValue(10);

    //initial listWidgets
    ui->listWidgetImgs->setDragEnabled(true);
    ui->listWidgetImgs->setMovement(QListWidget::Static);
    ui->listWidgetImgs->setFlow(QListWidget::TopToBottom);
    ui->listWidgetImgs->setResizeMode(QListWidget::Adjust);
    ui->listWidgetImgs->setViewMode(QListWidget::ListMode);
    ui->listWidgetImgs->setCurrentRow(0);
    ui->listWidgetImgs->setSelectionMode(QAbstractItemView::ExtendedSelection); //enable the listWidget to connect multiple Item
    ui->listWidgetImgs->setIconSize(QSize(200,200));

    //initial tree view
//    ui->treeViewForContent->setAnimated(true);//This property holds whether animations are enabled
//    ui->treeViewForContent->setSortingEnabled(true);

    connect(ui->spinBox_page,SIGNAL(valueChanged(int)),ui->progressBarLoader,SLOT(setValue(int)));
    connect(ui->pushButton_page_next,SIGNAL(clicked()),ui->spinBox_page,SLOT(setValue(int)));
    connect(ui->pushButton_page_prev,SIGNAL(clicked()),ui->spinBox_page,SLOT(setValue(int)));

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionOpenFiles_triggered()
{
    //returns the directory containing user document files.
    const QString FileRoot = QStandardPaths::writableLocation(QStandardPaths::DocumentsLocation);
    //get the file root of cbr
    QString DirRoot = QFileDialog::getOpenFileName(this, tr("CBR files loader"),
                                                      FileRoot,
                                                      "All Files (*);;Text Files (*.txt)");

    if(DirRoot.isEmpty()) {
        QMessageBox::warning(this, tr("warning!"), tr("the root path should not be empty"));
        return;
    }

    currentDirPath=DirRoot;
    ui->lineEditRoot->setText(currentDirPath);
}

void MainWindow::on_loadComicBook_clicked()
{
    ui->dataLoadding->setText("loadding");
    QFileInfo info(currentDirPath);
    QDir dir(tempPath);
    if(dir.exists()){
        dir.removeRecursively();
    }
    dir.mkpath(tempPath);
    qDebug()<<"current directory path is"<<info.absoluteFilePath();
    if(info.suffix()=="zip"){
        qDebug()<<"the file belongs to zip";
        zipManager->ListContents(info.absoluteFilePath());
        myfilesList = zipManager->ZipDecompressDir(currentDirPath,tempPath);
        ui->progressBarLoader->setRange(0,myfilesList.count());
        int value=0;
        foreach (QString item, myfilesList) {
            value++;
            ui->progressBarLoader->setValue(value);
        }
        filesModel->setStringList(myfilesList);
        ui->listViewForContent->setModel(filesModel);
//        ui->treeViewForContent->setModel(filesModel);
    }
}


void MainWindow::on_pushButtonImgReader_clicked()
{
    ui->dataLoadding->setText("Progress");
    ui->progressBarLoader->setValue(1);

    QStringList filters;
    imgsModel->setNameFilterDisables(false);
    imgsModel->setFilter(QDir::Dirs|QDir::Drives|QDir::Files|QDir::NoDotAndDotDot);
    filters<<"*.jpg"<<"*.bmp"<<"*.png";
    imgsModel->setNameFilters(filters);

    ui->listViewForContent->setMovement(QListView::Static);
    ui->listViewForContent->setViewMode(QListView::ListMode);
    ui->listViewForContent->setModel(imgsModel);
    ui->listViewForContent->setRootIndex(imgsModel->setRootPath(tempPath));
//    imgsModel->setRootPath("../bin/");
//    ui->treeViewForContent->setModel(imgsModel);
    on_initial_listwidget_items();

    if(!myfilesList.isEmpty()){
        myfilesList = myfilesList.filter("jpg")+myfilesList.filter("png")+myfilesList.filter("bmp");
        ui->spinBox_page->setRange(1,myfilesList.count());
        ui->progressBarLoader->setRange(1,myfilesList.count());
        ui->spinBox_page->setValue(1);
        ui->page_number->setText(QString::number(myfilesList.count()));
        myBrowserManager->setPageMinimum(1);
        myBrowserManager->setPageMaximum(myfilesList.count());
        myBrowserManager->setComicPage(1);

        foreach(QString item, myfilesList){
//            qDebug()<<item;
            QImage img = imgManager->getImg(item);
            onImgThumbnail(img);
        }
        ui->listWidgetImgs->setItemDelegate(new myListWidgetDelegate(ui->listWidgetImgs));
        qDebug()<<myBrowserManager->getComicPage();
        qDebug()<<myfilesList.at(myBrowserManager->getComicPage());
        imgManager->img_display_on_label(onImgShow(myfilesList.at(myBrowserManager->getComicPage())));

    }
    else{
        QMessageBox::warning(this,"IMGS_READER'","No loadable comics source found",QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes);
    }
}

void MainWindow::on_initial_listwidget_items()
{
    int n=ui->listWidgetImgs->count();
    if(n!=0){
        //delete previous items
        for(int i=0;i<n;i++)
        {
            QListWidgetItem *item = ui->listWidgetImgs->takeItem(0);
            delete item;
        }
    }
}

QImage MainWindow::onImgShow(const QString &img_path)
{
    QImage img = imgManager->loadImg(img_path);
    return img;
}

void MainWindow::on_pushButton_page_next_clicked()
{
    myBrowserManager->setComicPage(ui->spinBox_page->value()+1);
    if(myBrowserManager->getComicPage()<myBrowserManager->getPageMaximum()){
        ui->spinBox_page->setValue(myBrowserManager->getComicPage());
        imgManager->img_display_on_label(onImgShow(myfilesList.at(myBrowserManager->getComicPage())));
        ui->listWidgetImgs->setCurrentRow(myBrowserManager->getComicPage()-1);
    }
    else{
        myBrowserManager->setComicPage(myBrowserManager->getPageMaximum());
        QMessageBox::information(this,"Last page","this page is the last page");
    }
}


void MainWindow::on_pushButton_page_prev_clicked()
{
    myBrowserManager->setComicPage(ui->spinBox_page->value()-1);
    if(myBrowserManager->getComicPage()>=myBrowserManager->getPageMinimum()){
        ui->spinBox_page->setValue(myBrowserManager->getComicPage());
        imgManager->img_display_on_label(onImgShow(myfilesList.at(myBrowserManager->getComicPage())));
        ui->listWidgetImgs->setCurrentRow(myBrowserManager->getComicPage()-1);
    }
    else{
        myBrowserManager->setComicPage(myBrowserManager->getPageMinimum());
        QMessageBox::information(this,"Frist page","this page is the first page");
    }
}

void MainWindow::on_horizontalSlider_blur_valueChanged(int value)
{
    ui->horizontalSlider_blur->setValue(value);
    qDebug()<<"kernel size of blur"<<value;
    ui->horizontalSlider_box->setValue(0);
    ui->horizontalSlider_median->setValue(0);
    ui->horizontalSlider_gaussian->setValue(0);
}

void MainWindow::on_horizontalSlider_box_valueChanged(int value)
{
    ui->horizontalSlider_box->setValue(value);
    qDebug()<<"kernel size of box"<<value;
    ui->horizontalSlider_blur->setValue(0);
    ui->horizontalSlider_median->setValue(0);
    ui->horizontalSlider_gaussian->setValue(0);
}

void MainWindow::on_horizontalSlider_gaussian_valueChanged(int value)
{
    ui->horizontalSlider_gaussian->setValue(value);
    qDebug()<<"kernel size of gaussian"<<value;
    ui->horizontalSlider_box->setValue(0);
    ui->horizontalSlider_blur->setValue(0);
    ui->horizontalSlider_median->setValue(0);
}

void MainWindow::on_horizontalSlider_median_valueChanged(int value)
{
    ui->horizontalSlider_median->setValue(value);
    qDebug()<<"kernel size of median"<<value;
    ui->horizontalSlider_box->setValue(0);
    ui->horizontalSlider_blur->setValue(0);
    ui->horizontalSlider_gaussian->setValue(0);
}


void MainWindow::on_btn_application_clicked()
{
    if(!currentDirPath.isEmpty()){
        imgManager->loadImg(myfilesList.at(myBrowserManager->getComicPage()-1));
        ui->listWidgetImgs->setCurrentRow(myBrowserManager->getComicPage()-1);

        if(ui->horizontalSlider_box->value()!=0){
            imgManager->on_boxFilter(ui->horizontalSlider_box->value());
            QImage img = imgManager->update(myfilesList.at(myBrowserManager->getComicPage()-1));
            onSetCurrentItemWithNewImg(img);
        }
        else if (ui->horizontalSlider_blur->value()!=0) {
            imgManager->on_blur(ui->horizontalSlider_blur->value());
            QImage img = imgManager->update(myfilesList.at(myBrowserManager->getComicPage()-1));
            onSetCurrentItemWithNewImg(img);
        }
        else if(ui->horizontalSlider_median->value()!=0){
            imgManager->on_medianBlur(ui->horizontalSlider_median->value());
            QImage img = imgManager->update(myfilesList.at(myBrowserManager->getComicPage()-1));
            onSetCurrentItemWithNewImg(img);
        }
        else if(ui->horizontalSlider_gaussian->value()!=0){
            imgManager->on_gaussianBlur(ui->horizontalSlider_gaussian->value());
            QImage img = imgManager->update(myfilesList.at(myBrowserManager->getComicPage()-1));
            onSetCurrentItemWithNewImg(img);
        }
        else{
            QImage img = imgManager->keepOriginalImage(myfilesList.at(myBrowserManager->getComicPage()-1));
            onSetCurrentItemWithNewImg(img);
        }
    }
   else{
        QMessageBox::warning(this,"IMGS_FLITER","No comic images were found",QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes);
    }
}


void MainWindow::onImgThumbnail(QImage img)
{
    QPixmap pixmap = QPixmap(QPixmap::fromImage(img));
    QListWidgetItem *add_item = new QListWidgetItem(ui->listWidgetImgs);
    add_item->setData(Qt::UserRole+1,pixmap);
    add_item->setIcon(QIcon(pixmap));
    add_item->setTextAlignment(Qt::AlignCenter);
    add_item->setFlags(Qt::ItemIsEnabled|Qt::ItemIsSelectable);
//    add_item->setFlags(Qt::ItemIsEnabled);

    ui->listWidgetImgs->addItem(add_item);

}

void MainWindow::on_listWidgetImgs_itemClicked(QListWidgetItem *item)
{
   myBrowserManager->setComicPage(ui->listWidgetImgs->row(item)+1);
   ui->spinBox_page->setValue(myBrowserManager->getComicPage());
   if(ui->spinBox_page->value()==myBrowserManager->getPageMaximum()){
       imgManager->img_display_on_label(imgManager->loadImg(myfilesList.at(myBrowserManager->getComicPage()-1)));
   }else{
       imgManager->img_display_on_label(imgManager->loadImg(myfilesList.at(myBrowserManager->getComicPage())));
   }

//   QImage img = imgManager->update();
//   onSetCurrentItemWithNewImg(img);
}

void MainWindow::onSetCurrentItemWithNewImg(QImage &img)
{
    QPixmap pixmap = QPixmap(QPixmap::fromImage(img));
    QListWidgetItem *current_item = new QListWidgetItem(ui->listWidgetImgs);
    current_item->setData(Qt::UserRole+1,pixmap);
    current_item->setIcon(QIcon(pixmap));
    current_item->setTextAlignment(Qt::AlignCenter);
    current_item->setFlags(Qt::ItemIsEnabled|Qt::ItemIsSelectable);

    ui->listWidgetImgs->setCurrentItem(current_item);
    ui->listWidgetImgs->setItemDelegate(new myListWidgetDelegate(ui->listWidgetImgs));
}


void MainWindow::on_bt_grayscale_clicked()
{
    try {
        if(myfilesList.isEmpty()){
            throw "error";
        }else{
            QImage img = imgManager->on_grayscale(myfilesList.at(myBrowserManager->getComicPage()-1));
            onSetCurrentItemWithNewImg(img);
        }
    } catch (char const*) {
        QMessageBox::warning(this,"IMGS_GRAYSCALE","No comic images were found",QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes);
    }

}

void MainWindow::on_bt_edgeDetection_clicked()
{
    try {
        if(myfilesList.isEmpty()){
            throw "error";
        }else{
            QImage img = imgManager->on_egdeDetection(myfilesList.at(myBrowserManager->getComicPage()-1));
            onSetCurrentItemWithNewImg(img);
        }
    } catch (char const*) {
        QMessageBox::warning(this,"IMGS_EDGE","No comic images were found",QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes);
    }

}

void MainWindow::on_bt_save_changement_clicked()
{
    try {
        if(myfilesList.isEmpty()){
            throw "error";
        }else{
           imgManager->on_changementSave(myfilesList.at(myBrowserManager->getComicPage()-1));
        }
    } catch (char const*) {
        QMessageBox::warning(this,"IMGS_SAVED","No comic images were found",QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes);
    }

}

void MainWindow::on_bt_page_search_clicked()
{
    try {
        if(myfilesList.isEmpty()){
            throw "error";
        }else{
            myBrowserManager->setComicPage(ui->spinBox_page->value());
            imgManager->img_display_on_label(onImgShow(myfilesList.at(myBrowserManager->getComicPage())));
            ui->listWidgetImgs->setCurrentRow(myBrowserManager->getComicPage()-1);
        }
    } catch (char const*) {
        QMessageBox::warning(this,"IMGS_SEARCH","No comic images were found",QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes);
    }
}

void MainWindow::on_horizontalScrollBar_for_zoom_sliderReleased()
{
    try {
        if(myfilesList.isEmpty()){
            throw "error";
        }else{
            int mode=1;
            if(ui->comboBox_inter_methods->currentText()=="INTER_LINEAR") {
                mode=1;
            }else if(ui->comboBox_inter_methods->currentText()=="INTER_NEAREST"){
                mode=2;
            }else{
                mode=3;
            }
            qDebug()<<ui->horizontalScrollBar_for_zoom->value()/10.<<"|"<<mode;
            QImage img = imgManager->on_Interpolation_zoom(myfilesList.at(myBrowserManager->getComicPage()-1),ui->horizontalScrollBar_for_zoom->value(),mode);
//            onSetCurrentItemWithNewImg(img);
//             ui->listWidgetImgs->setCurrentRow(myBrowserManager->getComicPage()-1);
        }
    } catch (char const*) {
        QMessageBox::warning(this,"IMGS_ZOOM","No comic images were found",QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes);
    }
}

void MainWindow::on_actionsave_pdf_triggered()
{
    try {
        if(myfilesList.isEmpty()){
            throw "error";
        }else{
            imgManager->on_imgsSaved2PDF();
        }
    } catch (char const*) {
        QMessageBox::warning(this,"IMGS_SAVED2PDF","No comic images were found",QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes);
    }
}

void MainWindow::on_listViewForContent_doubleClicked(const QModelIndex &index)
{
//    QString str = ui->listViewForContent->model()->data(index).toString();
    qDebug()<<index.row();
    myBrowserManager->setComicPage(index.row()+1);
    ui->spinBox_page->setValue(myBrowserManager->getComicPage());
    imgManager->img_display_on_label(onImgShow(myfilesList.at(myBrowserManager->getComicPage())));
    ui->listWidgetImgs->setCurrentRow(myBrowserManager->getComicPage()-1);
}
