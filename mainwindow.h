#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLabel>
#include <QVector>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_playButton_clicked();

private:
    Ui::MainWindow *ui;
    QVector<QLabel*> playerCards;
    QVector<QLabel*> computerCards;

    void createDeck();
    void distributeCards();
    void updatePlayerCardsVisible();
    void updateComputerCardsHidden();
    void updateMiddleCardVisible();
    void startGame();
};

#endif // MAINWINDOW_H
