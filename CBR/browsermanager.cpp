#include "browsermanager.h"

browserManager::browserManager()
{
    page = 0;
    pageMaximum=0;
    pageMinimum=0;
}

browserManager::~browserManager()
{

}

int browserManager::getComicPage()
{
    return page;
}

void browserManager::setComicPage(const int p)
{
    page = p;
}

void browserManager::setPageMaximum(const int p)
{
    pageMaximum = p;
}

int browserManager::getPageMaximum()
{
    return pageMaximum;
}

void browserManager::setPageMinimum(const int p)
{
    pageMinimum = p;
}

int browserManager::getPageMinimum()
{
    return pageMinimum;
}
