//
//  DownloadManager.h
//  StackManagerQt/src
//
//  Created by Mohammed Nafees on 07/09/14.
//  Copyright (c) 2014 High Fidelity. All rights reserved.
//

#ifndef DOWNLOADMANAGER_H
#define DOWNLOADMANAGER_H

#include <QWidget>
#include <QHash>
#include <QEvent>
#include <QNetworkAccessManager>

#include "Downloader.h"

namespace Ui {
    class DownloadManager;
}

class DownloadManager : public QWidget
{
    Q_OBJECT
public:
    explicit DownloadManager(QNetworkAccessManager* manager, QWidget* parent = 0);
    ~DownloadManager();

    void downloadFile(QUrl url);

private slots:
    void onDownloadStarted(Downloader* downloader, QUrl url);
    void onDownloadCompleted(QUrl url);
    void onDownloadProgress(QUrl url, int percentage);
    void onDownloadFailed(QUrl url);
    void onInstallingFiles(QUrl url);
    void onFilesSuccessfullyInstalled(QUrl url);
    void onFilesInstallationFailed(QUrl url);

protected:
    void closeEvent(QCloseEvent*);

signals:
    void fileSuccessfullyInstalled(QUrl url);

private:
    Ui::DownloadManager* ui;
    QNetworkAccessManager* _manager;
    QHash<Downloader*, int> _downloaderHash;

    int downloaderRowIndexForUrl(QUrl url);
    Downloader* downloaderForUrl(QUrl url);
};

#endif
