#include "archivemanager.h"
#include <QFileInfo>


ArchiveManager::ArchiveManager()
{

}

ArchiveManager::~ArchiveManager()
{

}


QString ArchiveManager::getSrcPath()
{
    return srcPath;
}

QString ArchiveManager::getDstPath()
{
    return dstPath;
}

void ArchiveManager::setSrcPath(QString path)
{
    srcPath = path;
}

void ArchiveManager::setDstPath(QString path)
{
    dstPath = path;
}


ZipManager::~ZipManager()
{

}

void ZipManager::ZipCompressDir(QString ZipFile, QString DirPath)
{
    if(!JlCompress::compressDir(ZipFile,DirPath)){
        qDebug()<<"Warning: the path of zip file isn't correct.";
    }
    else {
        JlCompress::compressDir(ZipFile,DirPath);
        qDebug()<<"create the zip file"<<ZipFile;
    }
}

void ZipManager::ZipCompressFiles(QString ZipFile, QStringList Files)
{
    JlCompress::compressFiles(ZipFile,Files);
}

QStringList ZipManager::ZipDecompressDir(QString ZipFile, QString DirPath)
{
//    QDir dir(DirPath);
//    if(!dir.entryInfoList()){
//        qDebug()<<"the current dir has files, So we can't decompress files here";
//    }
    QStringList list = JlCompress::extractDir(ZipFile,DirPath);
    qDebug()<<"zip file path:"<<ZipFile;
    qDebug()<<"dst path:"<<DirPath;
    if(!list.empty()){
        foreach (QString item, list) {
           qDebug()<<"extract:"<<item;
        }
        qDebug()<<"extract finished.";
    }
    else{
         qDebug()<<"extract failed.";
    }
    return list;
}

QStringList ZipManager::ZipDecompressFiles(QString ZipFile, QString DirPath, QStringList Files)
{
    QStringList list = JlCompress::extractFiles(ZipFile,Files,DirPath);
    return list;
}

void ZipManager::ListContents(const QString &Files)
{
    QFile files(Files);
    if(files.exists()){
        QStringList list = JlCompress::getFileList(Files);
        foreach (QString item, list) {
            qDebug()<<"the files of current zip:"<<item;
        }
    }
    else{
        qDebug()<<"No zip files";
        return;
    }
}

void ZipManager::archiveStartExtract(const QString &Path)
{
    QFileInfo qFileInfo(Path);
    if(qFileInfo.suffix()=="zip"){
        setSrcPath(Path);
        QString dir = getDstPath();
        ziplist = ZipDecompressDir(getSrcPath(),dir);
        qDebug()<<"extraction finished.";
    }
    else{
        qDebug()<<"the archive path isn't correct";
    }
}


