#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>

#include <QRegExp>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setValidators();
}

MainWindow::~MainWindow()
{
    delete wordsValidator;
    delete stringValidator;
    delete ui;
}

void MainWindow::getString()
{
    s_string = ui->Str->text();
    if(s_string.isEmpty())
    {
        QMessageBox::warning(this,"Warning", "Please enter a string!");
    }
}

void MainWindow::getWords()
{
    QString words = ui->Words->text();
    words.simplified();
    words.replace(" ", "");

    d_words = words.split(',', QString::SkipEmptyParts);

    if(d_words.isEmpty())
    {
        QMessageBox::warning(this,"Warning", "Please enter a words!");
    }
}

void MainWindow::findLongestSubstr()
{
    int maxlen = 0;
    for(const auto& s : d_words)
    {
        if(s_string.contains(s, Qt::CaseInsensitive) && s.length() > maxlen)
        {
            maxlen = s.length();
            ui->resultBrowser->setText(s);
        }
    }
}

void MainWindow::setValidators()
{
    QRegExp expForWords("(\\w+[,]\\s?\\w*)+");
    QRegExp expForString("^([\\w\\-]+)");
    wordsValidator = new QRegExpValidator(expForWords, this);
    stringValidator = new QRegExpValidator(expForString, this);
    ui->Words->setValidator(wordsValidator);
    ui->Str->setValidator(wordsValidator);
}

void MainWindow::on_resultButton_clicked()
{
    getString();
    getWords();
    findLongestSubstr();
}
