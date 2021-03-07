#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QString>
#include <QStringListModel>
#include <QStandardItemModel>
#include <QFileSystemModel>
#include <QListWidgetItem>
#include <exception>
#include "archivemanager.h"
#include "imgmanager.h"
#include "mylistwidgetdelegate.h"
#include "browsermanager.h"


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_actionOpenFiles_triggered();

    void on_loadComicBook_clicked();

    void on_pushButtonImgReader_clicked();

    void on_initial_listwidget_items();

    QImage onImgShow(const QString &img_path);

    void on_pushButton_page_next_clicked();


    void on_pushButton_page_prev_clicked();

    void on_horizontalSlider_blur_valueChanged(int value);

    void on_horizontalSlider_box_valueChanged(int value);

    void on_horizontalSlider_gaussian_valueChanged(int value);

    void on_horizontalSlider_median_valueChanged(int value);


    void on_btn_application_clicked();

    void onImgThumbnail(QImage img);

    void on_listWidgetImgs_itemClicked(QListWidgetItem *item);

    void onSetCurrentItemWithNewImg(QImage &img);


    void on_bt_grayscale_clicked();

    void on_bt_edgeDetection_clicked();

    void on_bt_save_changement_clicked();

    void on_bt_page_search_clicked();


    void on_horizontalScrollBar_for_zoom_sliderReleased();

    void on_actionsave_pdf_triggered();

    void on_listViewForContent_doubleClicked(const QModelIndex &index);

private:
    Ui::MainWindow *ui;
    QString currentDirPath;
    QStringList myfilesList;
    ZipManager *zipManager;
    ImgManager *imgManager;
    QString tempPath;
    QStringListModel *filesModel;
    QFileSystemModel *imgsModel;
    browserManager *myBrowserManager;

};


#endif // MAINWINDOW_H
