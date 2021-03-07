#include "mylistwidgetdelegate.h"
#include <QPixmap>
#include <QSize>
#include <QPainter>


myListWidgetDelegate::myListWidgetDelegate(QObject *pParent):QStyledItemDelegate(pParent)
{

}

myListWidgetDelegate::~myListWidgetDelegate()
{

}

void myListWidgetDelegate::paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    //set the size of pixmap
    {


        //set a margin
        QRect rect = option.rect.adjusted(1,1,-1,-1);

        //we can also set the size of hont etc...
        painter->setBrush(QColor(199, 237, 204));//Looking for eye protection colors online to fill the background to protect your eyes:)
        painter->drawRoundedRect(rect, 1, 1);
        painter->setBrush(Qt::NoBrush);

        QPixmap pixmap = index.data(Qt::UserRole + 1).value<QPixmap>();
        QSize pixSize = pixmap.size().scaled(rect.size(),Qt::KeepAspectRatio);
//        QSize pixSize = pixmap.size();

        //if we set the size model equal Qt::KeepAspectRatio, sometimes it can't be use all rect. so in this time, we set the rect with new margin
        int offset_x = ceil((rect.width()-pixSize.width())/2);
        int offset_y = ceil((rect.height()-pixSize.height())/2);
        QRect rect_adjusted = rect.adjusted(offset_x,offset_y,-offset_x,-offset_y);
        painter->drawPixmap(rect_adjusted,pixmap);
    }


}

QSize myListWidgetDelegate::sizeHint(const QStyleOptionViewItem &option, const QModelIndex &) const
{
      return QSize(option.rect.height(), option.rect.width()*4/5.);
}
