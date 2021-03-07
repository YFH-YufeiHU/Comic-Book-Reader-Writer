#ifndef MYLISTWIDGETDELEGATE_H
#define MYLISTWIDGETDELEGATE_H
#include <QStyledItemDelegate>
#include <math.h>

/*
The propuse of this class is to define the icon size of QListWidget according to the size of its windows.
*/

class myListWidgetDelegate:public QStyledItemDelegate
{
     Q_OBJECT
public:
    myListWidgetDelegate(QObject* pParent);
    virtual ~myListWidgetDelegate();
private:
    //define the way of paint
    void paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const;

    //define the size of unit grill
    QSize sizeHint(const QStyleOptionViewItem &option, const QModelIndex &index) const;
};

#endif // MYLISTWIDGETDELEGATE_H
