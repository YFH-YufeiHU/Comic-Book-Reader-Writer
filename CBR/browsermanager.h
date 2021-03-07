#ifndef BROWSERMANAGER_H
#define BROWSERMANAGER_H

#include <QWidget>

class browserManager : public QWidget
{
public:
    browserManager();
    ~browserManager();
    int getComicPage();
    void setComicPage(const int p);
    void setPageMaximum(const int p);
    int getPageMaximum();
    void setPageMinimum(const int p);
    int getPageMinimum();


private:
    int page;
    int pageMaximum;
    int pageMinimum;
};

#endif // BROWSERMANAGER_H
