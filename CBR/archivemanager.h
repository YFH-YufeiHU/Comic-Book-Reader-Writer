#ifndef ARCHIVEMANAGER_H
#define ARCHIVEMANAGER_H

#include <QString>
#include <QDir>
#include <iostream>
#include <string>
#include <QDebug>
#include <QFile>
#include <quazip/quazip.h>
#include <quazip/JlCompress.h>

class ArchiveManager
{
public:
    ArchiveManager();
    virtual ~ArchiveManager();

    QString getSrcPath();
    QString getDstPath();
    void setSrcPath(QString path);
    void setDstPath(QString path);

    virtual void archiveStartExtract(const QString&)=0;
    //list the contents of a zip file
    virtual void ListContents(const QString&)=0;
public:
    QStringList ZipList;
private:
    QString srcPath;
    QString dstPath;
};
class ZipManager:public ArchiveManager
{

public:

    ZipManager(){};
    virtual~ZipManager();

    //compress a dir
    void ZipCompressDir(QString ZipFile,QString DirPath);
    //compress a single file
    void ZipCompressFiles(QString ZipFile,QStringList Files);
    //decompress all files of a zip file
    QStringList ZipDecompressDir(QString ZipFile,QString DirPath);
    //decompress part files from a zip file
    QStringList ZipDecompressFiles(QString ZipFile,QString DirPath,QStringList Files);

    void ListContents(const QString &) ;
//    void ListContents(const QString &Files) ;
    void archiveStartExtract(const QString &Path);

public:
    QStringList ziplist;

};


#endif // ARCHIVEMANAGER_H
