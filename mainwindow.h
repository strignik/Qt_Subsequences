#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QString>
#include <QStringList>
#include <QRegExpValidator>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    QRegExpValidator* stringValidator;
    QRegExpValidator* wordsValidator;
    QString s_string;
    QStringList d_words;

    void getString();
    void getWords();
    void findLongestSubstr();
    void setValidators();
private slots:
    void on_resultButton_clicked();
};

#endif // MAINWINDOW_H
