/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListView>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollBar>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionOpenFiles;
    QAction *actionsave_pdf;
    QWidget *centralwidget;
    QHBoxLayout *horizontalLayout_15;
    QHBoxLayout *horizontalLayout_14;
    QVBoxLayout *verticalLayout_8;
    QFrame *frame_2;
    QHBoxLayout *horizontalLayout_12;
    QVBoxLayout *verticalLayout_6;
    QVBoxLayout *verticalLayout_5;
    QHBoxLayout *horizontalLayout_4;
    QLabel *dataLoadding;
    QProgressBar *progressBarLoader;
    QHBoxLayout *horizontalLayout_3;
    QListView *listViewForContent;
    QListWidget *listWidgetImgs;
    QHBoxLayout *horizontalLayout;
    QLabel *root;
    QLineEdit *lineEditRoot;
    QFrame *frame_zoom;
    QHBoxLayout *horizontalLayout_11;
    QHBoxLayout *horizontalLayout_10;
    QLabel *label_3;
    QComboBox *comboBox_inter_methods;
    QScrollBar *horizontalScrollBar_for_zoom;
    QVBoxLayout *verticalLayout_9;
    QFrame *frame_3;
    QHBoxLayout *horizontalLayout_13;
    QVBoxLayout *verticalLayout_7;
    QPushButton *loadComicBook;
    QFormLayout *formLayout_3;
    QLabel *label;
    QPushButton *pushButtonImgReader;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *pushButton_page_next;
    QPushButton *pushButton_page_prev;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_9;
    QFormLayout *formLayout_2;
    QLabel *page;
    QSpinBox *spinBox_page;
    QLabel *label_2;
    QLineEdit *page_number;
    QPushButton *bt_page_search;
    QFrame *frame_filter;
    QHBoxLayout *horizontalLayout_7;
    QVBoxLayout *verticalLayout_4;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_6;
    QFormLayout *formLayout;
    QLabel *blur;
    QSlider *horizontalSlider_blur;
    QLabel *box;
    QSlider *horizontalSlider_box;
    QLabel *gaussian;
    QLabel *median;
    QSlider *horizontalSlider_gaussian;
    QSlider *horizontalSlider_median;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout_5;
    QPushButton *btn_application;
    QPushButton *bt_grayscale;
    QHBoxLayout *horizontalLayout_6;
    QPushButton *bt_edgeDetection;
    QPushButton *bt_save_changement;
    QFrame *frame_label_display;
    QHBoxLayout *horizontalLayout_8;
    QLabel *label_img;
    QMenuBar *menubar;
    QMenu *menuFiles;
    QMenu *menuSet;
    QMenu *menuHelp;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(890, 738);
        actionOpenFiles = new QAction(MainWindow);
        actionOpenFiles->setObjectName(QString::fromUtf8("actionOpenFiles"));
        actionsave_pdf = new QAction(MainWindow);
        actionsave_pdf->setObjectName(QString::fromUtf8("actionsave_pdf"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        horizontalLayout_15 = new QHBoxLayout(centralwidget);
        horizontalLayout_15->setObjectName(QString::fromUtf8("horizontalLayout_15"));
        horizontalLayout_14 = new QHBoxLayout();
        horizontalLayout_14->setObjectName(QString::fromUtf8("horizontalLayout_14"));
        verticalLayout_8 = new QVBoxLayout();
        verticalLayout_8->setObjectName(QString::fromUtf8("verticalLayout_8"));
        frame_2 = new QFrame(centralwidget);
        frame_2->setObjectName(QString::fromUtf8("frame_2"));
        frame_2->setFrameShape(QFrame::StyledPanel);
        frame_2->setFrameShadow(QFrame::Raised);
        horizontalLayout_12 = new QHBoxLayout(frame_2);
        horizontalLayout_12->setObjectName(QString::fromUtf8("horizontalLayout_12"));
        verticalLayout_6 = new QVBoxLayout();
        verticalLayout_6->setObjectName(QString::fromUtf8("verticalLayout_6"));
        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        horizontalLayout_4->setContentsMargins(-1, -1, 9, -1);
        dataLoadding = new QLabel(frame_2);
        dataLoadding->setObjectName(QString::fromUtf8("dataLoadding"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(dataLoadding->sizePolicy().hasHeightForWidth());
        dataLoadding->setSizePolicy(sizePolicy);

        horizontalLayout_4->addWidget(dataLoadding);

        progressBarLoader = new QProgressBar(frame_2);
        progressBarLoader->setObjectName(QString::fromUtf8("progressBarLoader"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(progressBarLoader->sizePolicy().hasHeightForWidth());
        progressBarLoader->setSizePolicy(sizePolicy1);
        progressBarLoader->setValue(0);

        horizontalLayout_4->addWidget(progressBarLoader);


        verticalLayout_5->addLayout(horizontalLayout_4);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        listViewForContent = new QListView(frame_2);
        listViewForContent->setObjectName(QString::fromUtf8("listViewForContent"));

        horizontalLayout_3->addWidget(listViewForContent);

        listWidgetImgs = new QListWidget(frame_2);
        listWidgetImgs->setObjectName(QString::fromUtf8("listWidgetImgs"));
        QSizePolicy sizePolicy2(QSizePolicy::Expanding, QSizePolicy::Preferred);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(listWidgetImgs->sizePolicy().hasHeightForWidth());
        listWidgetImgs->setSizePolicy(sizePolicy2);
        listWidgetImgs->setMaximumSize(QSize(16777215, 16777215));
        listWidgetImgs->setResizeMode(QListView::Adjust);
        listWidgetImgs->setBatchSize(100);

        horizontalLayout_3->addWidget(listWidgetImgs);

        horizontalLayout_3->setStretch(0, 1);
        horizontalLayout_3->setStretch(1, 5);

        verticalLayout_5->addLayout(horizontalLayout_3);

        verticalLayout_5->setStretch(0, 1);
        verticalLayout_5->setStretch(1, 5);

        verticalLayout_6->addLayout(verticalLayout_5);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setSizeConstraint(QLayout::SetDefaultConstraint);
        root = new QLabel(frame_2);
        root->setObjectName(QString::fromUtf8("root"));
        sizePolicy.setHeightForWidth(root->sizePolicy().hasHeightForWidth());
        root->setSizePolicy(sizePolicy);

        horizontalLayout->addWidget(root);

        lineEditRoot = new QLineEdit(frame_2);
        lineEditRoot->setObjectName(QString::fromUtf8("lineEditRoot"));
        QSizePolicy sizePolicy3(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(lineEditRoot->sizePolicy().hasHeightForWidth());
        lineEditRoot->setSizePolicy(sizePolicy3);

        horizontalLayout->addWidget(lineEditRoot);

        horizontalLayout->setStretch(0, 1);
        horizontalLayout->setStretch(1, 10);

        verticalLayout_6->addLayout(horizontalLayout);


        horizontalLayout_12->addLayout(verticalLayout_6);


        verticalLayout_8->addWidget(frame_2);

        frame_zoom = new QFrame(centralwidget);
        frame_zoom->setObjectName(QString::fromUtf8("frame_zoom"));
        frame_zoom->setFrameShape(QFrame::StyledPanel);
        frame_zoom->setFrameShadow(QFrame::Raised);
        frame_zoom->setMidLineWidth(1);
        horizontalLayout_11 = new QHBoxLayout(frame_zoom);
        horizontalLayout_11->setObjectName(QString::fromUtf8("horizontalLayout_11"));
        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setObjectName(QString::fromUtf8("horizontalLayout_10"));
        label_3 = new QLabel(frame_zoom);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        horizontalLayout_10->addWidget(label_3);

        comboBox_inter_methods = new QComboBox(frame_zoom);
        comboBox_inter_methods->addItem(QString());
        comboBox_inter_methods->addItem(QString());
        comboBox_inter_methods->addItem(QString());
        comboBox_inter_methods->setObjectName(QString::fromUtf8("comboBox_inter_methods"));

        horizontalLayout_10->addWidget(comboBox_inter_methods);

        horizontalScrollBar_for_zoom = new QScrollBar(frame_zoom);
        horizontalScrollBar_for_zoom->setObjectName(QString::fromUtf8("horizontalScrollBar_for_zoom"));
        horizontalScrollBar_for_zoom->setOrientation(Qt::Horizontal);

        horizontalLayout_10->addWidget(horizontalScrollBar_for_zoom);

        horizontalLayout_10->setStretch(0, 1);
        horizontalLayout_10->setStretch(1, 2);
        horizontalLayout_10->setStretch(2, 4);

        horizontalLayout_11->addLayout(horizontalLayout_10);


        verticalLayout_8->addWidget(frame_zoom);


        horizontalLayout_14->addLayout(verticalLayout_8);

        verticalLayout_9 = new QVBoxLayout();
        verticalLayout_9->setObjectName(QString::fromUtf8("verticalLayout_9"));
        frame_3 = new QFrame(centralwidget);
        frame_3->setObjectName(QString::fromUtf8("frame_3"));
        frame_3->setFrameShape(QFrame::StyledPanel);
        frame_3->setFrameShadow(QFrame::Raised);
        horizontalLayout_13 = new QHBoxLayout(frame_3);
        horizontalLayout_13->setObjectName(QString::fromUtf8("horizontalLayout_13"));
        verticalLayout_7 = new QVBoxLayout();
        verticalLayout_7->setObjectName(QString::fromUtf8("verticalLayout_7"));
        loadComicBook = new QPushButton(frame_3);
        loadComicBook->setObjectName(QString::fromUtf8("loadComicBook"));
        sizePolicy3.setHeightForWidth(loadComicBook->sizePolicy().hasHeightForWidth());
        loadComicBook->setSizePolicy(sizePolicy3);

        verticalLayout_7->addWidget(loadComicBook);

        formLayout_3 = new QFormLayout();
        formLayout_3->setObjectName(QString::fromUtf8("formLayout_3"));
        label = new QLabel(frame_3);
        label->setObjectName(QString::fromUtf8("label"));
        sizePolicy3.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy3);

        formLayout_3->setWidget(0, QFormLayout::LabelRole, label);

        pushButtonImgReader = new QPushButton(frame_3);
        pushButtonImgReader->setObjectName(QString::fromUtf8("pushButtonImgReader"));
        sizePolicy3.setHeightForWidth(pushButtonImgReader->sizePolicy().hasHeightForWidth());
        pushButtonImgReader->setSizePolicy(sizePolicy3);

        formLayout_3->setWidget(0, QFormLayout::FieldRole, pushButtonImgReader);


        verticalLayout_7->addLayout(formLayout_3);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        pushButton_page_next = new QPushButton(frame_3);
        pushButton_page_next->setObjectName(QString::fromUtf8("pushButton_page_next"));
        sizePolicy1.setHeightForWidth(pushButton_page_next->sizePolicy().hasHeightForWidth());
        pushButton_page_next->setSizePolicy(sizePolicy1);

        horizontalLayout_2->addWidget(pushButton_page_next);

        pushButton_page_prev = new QPushButton(frame_3);
        pushButton_page_prev->setObjectName(QString::fromUtf8("pushButton_page_prev"));
        sizePolicy1.setHeightForWidth(pushButton_page_prev->sizePolicy().hasHeightForWidth());
        pushButton_page_prev->setSizePolicy(sizePolicy1);

        horizontalLayout_2->addWidget(pushButton_page_prev);


        verticalLayout_7->addLayout(horizontalLayout_2);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setObjectName(QString::fromUtf8("horizontalLayout_9"));
        formLayout_2 = new QFormLayout();
        formLayout_2->setObjectName(QString::fromUtf8("formLayout_2"));
        page = new QLabel(frame_3);
        page->setObjectName(QString::fromUtf8("page"));
        sizePolicy1.setHeightForWidth(page->sizePolicy().hasHeightForWidth());
        page->setSizePolicy(sizePolicy1);

        formLayout_2->setWidget(0, QFormLayout::LabelRole, page);

        spinBox_page = new QSpinBox(frame_3);
        spinBox_page->setObjectName(QString::fromUtf8("spinBox_page"));
        spinBox_page->setDisplayIntegerBase(10);

        formLayout_2->setWidget(0, QFormLayout::FieldRole, spinBox_page);


        horizontalLayout_9->addLayout(formLayout_2);

        label_2 = new QLabel(frame_3);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout_9->addWidget(label_2);

        page_number = new QLineEdit(frame_3);
        page_number->setObjectName(QString::fromUtf8("page_number"));

        horizontalLayout_9->addWidget(page_number);


        verticalLayout->addLayout(horizontalLayout_9);

        bt_page_search = new QPushButton(frame_3);
        bt_page_search->setObjectName(QString::fromUtf8("bt_page_search"));

        verticalLayout->addWidget(bt_page_search);


        verticalLayout_7->addLayout(verticalLayout);


        horizontalLayout_13->addLayout(verticalLayout_7);


        verticalLayout_9->addWidget(frame_3);

        frame_filter = new QFrame(centralwidget);
        frame_filter->setObjectName(QString::fromUtf8("frame_filter"));
        frame_filter->setFrameShape(QFrame::StyledPanel);
        frame_filter->setFrameShadow(QFrame::Raised);
        horizontalLayout_7 = new QHBoxLayout(frame_filter);
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        label_6 = new QLabel(frame_filter);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        sizePolicy3.setHeightForWidth(label_6->sizePolicy().hasHeightForWidth());
        label_6->setSizePolicy(sizePolicy3);

        verticalLayout_2->addWidget(label_6);

        formLayout = new QFormLayout();
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        blur = new QLabel(frame_filter);
        blur->setObjectName(QString::fromUtf8("blur"));

        formLayout->setWidget(0, QFormLayout::LabelRole, blur);

        horizontalSlider_blur = new QSlider(frame_filter);
        horizontalSlider_blur->setObjectName(QString::fromUtf8("horizontalSlider_blur"));
        horizontalSlider_blur->setOrientation(Qt::Horizontal);

        formLayout->setWidget(0, QFormLayout::FieldRole, horizontalSlider_blur);

        box = new QLabel(frame_filter);
        box->setObjectName(QString::fromUtf8("box"));

        formLayout->setWidget(1, QFormLayout::LabelRole, box);

        horizontalSlider_box = new QSlider(frame_filter);
        horizontalSlider_box->setObjectName(QString::fromUtf8("horizontalSlider_box"));
        horizontalSlider_box->setOrientation(Qt::Horizontal);

        formLayout->setWidget(1, QFormLayout::FieldRole, horizontalSlider_box);

        gaussian = new QLabel(frame_filter);
        gaussian->setObjectName(QString::fromUtf8("gaussian"));

        formLayout->setWidget(2, QFormLayout::LabelRole, gaussian);

        median = new QLabel(frame_filter);
        median->setObjectName(QString::fromUtf8("median"));

        formLayout->setWidget(3, QFormLayout::LabelRole, median);

        horizontalSlider_gaussian = new QSlider(frame_filter);
        horizontalSlider_gaussian->setObjectName(QString::fromUtf8("horizontalSlider_gaussian"));
        horizontalSlider_gaussian->setOrientation(Qt::Horizontal);

        formLayout->setWidget(3, QFormLayout::FieldRole, horizontalSlider_gaussian);

        horizontalSlider_median = new QSlider(frame_filter);
        horizontalSlider_median->setObjectName(QString::fromUtf8("horizontalSlider_median"));
        horizontalSlider_median->setOrientation(Qt::Horizontal);

        formLayout->setWidget(2, QFormLayout::FieldRole, horizontalSlider_median);


        verticalLayout_2->addLayout(formLayout);


        verticalLayout_4->addLayout(verticalLayout_2);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        btn_application = new QPushButton(frame_filter);
        btn_application->setObjectName(QString::fromUtf8("btn_application"));
        sizePolicy3.setHeightForWidth(btn_application->sizePolicy().hasHeightForWidth());
        btn_application->setSizePolicy(sizePolicy3);

        horizontalLayout_5->addWidget(btn_application);

        bt_grayscale = new QPushButton(frame_filter);
        bt_grayscale->setObjectName(QString::fromUtf8("bt_grayscale"));

        horizontalLayout_5->addWidget(bt_grayscale);


        verticalLayout_3->addLayout(horizontalLayout_5);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        bt_edgeDetection = new QPushButton(frame_filter);
        bt_edgeDetection->setObjectName(QString::fromUtf8("bt_edgeDetection"));

        horizontalLayout_6->addWidget(bt_edgeDetection);

        bt_save_changement = new QPushButton(frame_filter);
        bt_save_changement->setObjectName(QString::fromUtf8("bt_save_changement"));

        horizontalLayout_6->addWidget(bt_save_changement);


        verticalLayout_3->addLayout(horizontalLayout_6);


        verticalLayout_4->addLayout(verticalLayout_3);


        horizontalLayout_7->addLayout(verticalLayout_4);


        verticalLayout_9->addWidget(frame_filter);

        frame_label_display = new QFrame(centralwidget);
        frame_label_display->setObjectName(QString::fromUtf8("frame_label_display"));
        frame_label_display->setFrameShape(QFrame::StyledPanel);
        frame_label_display->setFrameShadow(QFrame::Raised);
        horizontalLayout_8 = new QHBoxLayout(frame_label_display);
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
        label_img = new QLabel(frame_label_display);
        label_img->setObjectName(QString::fromUtf8("label_img"));
        QSizePolicy sizePolicy4(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(label_img->sizePolicy().hasHeightForWidth());
        label_img->setSizePolicy(sizePolicy4);

        horizontalLayout_8->addWidget(label_img);


        verticalLayout_9->addWidget(frame_label_display);


        horizontalLayout_14->addLayout(verticalLayout_9);

        horizontalLayout_14->setStretch(0, 3);
        horizontalLayout_14->setStretch(1, 1);

        horizontalLayout_15->addLayout(horizontalLayout_14);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 890, 22));
        menuFiles = new QMenu(menubar);
        menuFiles->setObjectName(QString::fromUtf8("menuFiles"));
        menuSet = new QMenu(menubar);
        menuSet->setObjectName(QString::fromUtf8("menuSet"));
        menuHelp = new QMenu(menubar);
        menuHelp->setObjectName(QString::fromUtf8("menuHelp"));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        menubar->addAction(menuFiles->menuAction());
        menubar->addAction(menuSet->menuAction());
        menubar->addAction(menuHelp->menuAction());
        menuFiles->addSeparator();
        menuFiles->addSeparator();
        menuFiles->addAction(actionOpenFiles);
        menuFiles->addSeparator();
        menuFiles->addAction(actionsave_pdf);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        actionOpenFiles->setText(QCoreApplication::translate("MainWindow", "Open", nullptr));
        actionsave_pdf->setText(QCoreApplication::translate("MainWindow", "save(pdf)", nullptr));
        dataLoadding->setText(QCoreApplication::translate("MainWindow", "loadding", nullptr));
        root->setText(QCoreApplication::translate("MainWindow", "Root:", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "Interpolation:", nullptr));
        comboBox_inter_methods->setItemText(0, QCoreApplication::translate("MainWindow", "INTER_LINEAR", nullptr));
        comboBox_inter_methods->setItemText(1, QCoreApplication::translate("MainWindow", "INTER_NEAREST", nullptr));
        comboBox_inter_methods->setItemText(2, QCoreApplication::translate("MainWindow", "INTER_CUBIC", nullptr));

#if QT_CONFIG(tooltip)
        horizontalScrollBar_for_zoom->setToolTip(QCoreApplication::translate("MainWindow", "<html><head/><body><pre style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:'monospace';\"><br/></pre></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        loadComicBook->setText(QCoreApplication::translate("MainWindow", "CBLoader", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "ImgsLoad:", nullptr));
        pushButtonImgReader->setText(QCoreApplication::translate("MainWindow", "Reader", nullptr));
        pushButton_page_next->setText(QCoreApplication::translate("MainWindow", "PageDown", nullptr));
        pushButton_page_prev->setText(QCoreApplication::translate("MainWindow", "PageUp", nullptr));
        page->setText(QCoreApplication::translate("MainWindow", "page:", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "/", nullptr));
        bt_page_search->setText(QCoreApplication::translate("MainWindow", "search", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "Filters", nullptr));
        blur->setText(QCoreApplication::translate("MainWindow", "blur", nullptr));
        box->setText(QCoreApplication::translate("MainWindow", "box", nullptr));
        gaussian->setText(QCoreApplication::translate("MainWindow", "gaussian", nullptr));
        median->setText(QCoreApplication::translate("MainWindow", "median", nullptr));
        btn_application->setText(QCoreApplication::translate("MainWindow", "application", nullptr));
        bt_grayscale->setText(QCoreApplication::translate("MainWindow", "grayscale", nullptr));
        bt_edgeDetection->setText(QCoreApplication::translate("MainWindow", "edge", nullptr));
        bt_save_changement->setText(QCoreApplication::translate("MainWindow", "save", nullptr));
        label_img->setText(QCoreApplication::translate("MainWindow", "img", nullptr));
        menuFiles->setTitle(QCoreApplication::translate("MainWindow", "Files", nullptr));
        menuSet->setTitle(QCoreApplication::translate("MainWindow", "View", nullptr));
        menuHelp->setTitle(QCoreApplication::translate("MainWindow", "Help", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
