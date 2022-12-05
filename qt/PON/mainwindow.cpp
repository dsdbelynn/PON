#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QtNetwork>
#include <QDebug>
#include <QDateTime>
#include "dialog.h"

#define API_POE_LEAGUE "http://api.pathofexile.com/leagues?type=main&compact=1"
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    listLeague.clear();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::setComboBox(QJsonDocument doc)
{
    listLeague.clear();
    ui->comboBox->clear();
    auto array = doc.array();
    if(array.isEmpty())
    {
        ui->label->setText(tr("未获取到赛季列表"));
    }
    for(int i = 0; i < array.size(); i++)
    {
        auto obj = array[i];
        if(obj.isObject())
        {
            auto o = obj.toObject();
            auto id = o.find(QString("id"));
            if(id.value().isString())
            {
                QString str = id.value().toString();
                if(str.contains("SSF"))
                {
                    continue;
                }
                else
                {
                    listLeague.append(str);
                }
            }
        }
    }
    ui->comboBox->addItems(listLeague);
    form.show();
}

void MainWindow::on_pushButton_clicked()
{
    auto time = QDateTime::currentDateTime();
    //auto url = QUrl("https://poe.ninja/api/data/currencyoverview?type=Currency&league=Kalandra");
    auto url = QUrl(API_POE_LEAGUE);
    QNetworkRequest request;
    QNetworkReply *reply;
    QNetworkAccessManager manager;
    QEventLoop loop;
    request.setUrl(url);
    request.setRawHeader("User-Agent", "Lynn");
    request.setRawHeader("Accept", "*/*");
    request.setRawHeader("Host", "api.pathofexile.com");
    request.setRawHeader("Connection", "keep-alive");
    reply = manager.get(request);
    QObject::connect(reply, SIGNAL(finished()), &loop, SLOT(quit()));
    loop.exec();
    QByteArray data = reply->readAll();
    auto doc = QJsonDocument::fromJson(data);
    QByteArray content(doc.toJson(QJsonDocument::Indented));
    ui->textEdit->insertPlainText(content);
    //ui->textEdit->insertPlainText(data);
    auto time1 = QDateTime::currentDateTime();
    ui->label->setText(tr("耗时：") + QDateTime::fromMSecsSinceEpoch(time1.toMSecsSinceEpoch() - time.toMSecsSinceEpoch()).toString("mm:ss.zzz"));
    setComboBox(doc);
}
