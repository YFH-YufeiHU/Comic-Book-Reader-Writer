#ifndef IMGMANAGER_H
#define IMGMANAGER_H

#include <QString>
#include <opencv4/opencv2/opencv.hpp>
#include <opencv4/opencv2/imgcodecs.hpp>
#include <opencv4/opencv2/highgui.hpp>
#include <opencv4/opencv2/core.hpp>
#include <iostream>
#include <QImage>
#include <QWidget>
#include <QLabel>
#include <QPixmap>
#include <QDir>
#include <QMessageBox>
#include <math.h>
#include <Magick++.h>

class ImgManager : public QWidget
{
    Q_OBJECT
public:
    explicit ImgManager( QLabel *qlabel, QWidget *parent = 0);
//    explicit ImgManager(QWidget *parent = 0);
    void img_display_on_label(const QImage img);

    QImage getImg(const QString& srcPath);

    QImage loadImg(const QString& srcPath);

    QImage update(const QString &srcPath);

    QImage keepOriginalImage(const QString &srcPath);

    void on_boxFilter(const int kernel_size);

    void on_blur(const int kernel_seze);

    void on_gaussianBlur(const int kernel_size);

    void on_medianBlur(const int kernel_size);

    QImage on_grayscale(const QString &srcPath);

    QImage on_egdeDetection(const QString &srcPath);

    void on_changementSave(const QString &srcPath);

    void on_imgsSaved2PDF();

    QImage on_Interpolation_zoom(const QString &srcPath, const int factor, const int mode);


private:


private:    
    QLabel *img_display_region;
    cv::Mat srcImg;
    cv::Mat dstImg;
    QString imgType;
//    QStringList imgsPathList;
};

#endif // IMGMANAGER_H
