#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <cstdlib>
#include <ctime>

// ...
MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);
    // Initialisation de l'interface utilisateur
    // ...

    // Initialisation du générateur de nombres aléatoires
    srand(time(nullptr));

    // Initialisation du paquet de cartes
    createDeck();
}

void MainWindow::on_playButton_clicked() {
    // Distribution des cartes aux joueurs et au milieu
    distributeCards();

    // Mise à jour de l'interface pour montrer les cartes
    updatePlayerCardsVisible();
    updateComputerCardsHidden();
    updateMiddleCardVisible();

    // Lancement du jeu avec les règles décrites
    startGame();
}

void MainWindow::createDeck() {
    // Types de cartes et leurs valeurs
    QStringList types = {"Bâtons", "Coupes", "Épées", "Or"};
    QVector<QString> values = {"1", "2", "3", "4", "5", "6", "7", "10", "11", "12"};

    // Création du paquet de cartes
    QVector<QString> deck;
    for (const QString& type : types) {
        for (const QString& value : values) {
            QString card = type + "_" + value; // Exemple : "Bâtons_1", "Coupes_2", ...
            deck.append(card);
        }
    }

    // Mélanger le paquet de cartes
    std::random_device rd;
    std::mt19937 g(rd());
    std::shuffle(deck.begin(), deck.end(), g);

    // Ici, vous pouvez stocker le paquet de cartes dans une variable membre ou utiliser directement le paquet
    // Par exemple : this->deck = deck; (où deck est un QVector<QString> déclaré dans la classe MainWindow)
}

void MainWindow::distributeCards() {
    // Vérifier si le paquet de cartes est vide
    if (deck.isEmpty()) {
        qDebug() << "Le paquet de cartes est vide.";
        return;
    }

    // Distribuer 4 cartes à chaque joueur
    for (int i = 0; i < 4; ++i) {
        // Distribuer les cartes aux joueurs (faces visibles pour le joueur humain)
        QString playerCard = deck.takeLast();  // Prendre la carte du dessus du paquet
        QLabel* playerCardLabel = new QLabel(this);
        // Afficher l'image de la carte playerCard sur playerCardLabel
        // ...
        playerCards.append(playerCardLabel);  // Ajouter la carte au vecteur de cartes du joueur

        // Distribuer les cartes à l'ordinateur (faces cachées)
        QString computerCard = deck.takeLast();  // Prendre la carte du dessus du paquet
        QLabel* computerCardLabel = new QLabel(this);
        // Afficher le dos de la carte sur computerCardLabel
        // ...
        computerCards.append(computerCardLabel);  // Ajouter la carte au vecteur de cartes de l'ordinateur
    }

    // Distribuer une carte au milieu (visible)
    QString middleCard = deck.takeLast();  // Prendre la carte du dessus du paquet
    QLabel* middleCardLabel = new QLabel(this);
    // Afficher l'image de la carte middleCard sur middleCardLabel
    // ...
    // Utiliser middleCardLabel pour afficher la carte au milieu

    // À ce stade, vous avez distribué les cartes aux joueurs et au milieu
    // Vous devrez ajouter la logique pour afficher les images des cartes sur les QLabel appropriés
}


void MainWindow::updatePlayerCardsVisible() {
    // Assurez-vous que playerCards contient les QLabel représentant les cartes du joueur

    // Parcourir les cartes du joueur et afficher les images associées sur les QLabel correspondants
    for (int i = 0; i < playerCards.size(); ++i) {
        QString cardImagePath =;
        QPixmap cardImage(cardImagePath);

        // Assurez-vous que playerCards[i] représente le QLabel pour la carte actuelle
        playerCards[i]->setPixmap(cardImage); // Afficher l'image de la carte sur le QLabel
        playerCards[i]->setVisible(true); // Rendre la carte visible
    }
}


void MainWindow::updateComputerCardsHidden() {
    // Assurez-vous que computerCards contient les QLabel représentant les cartes de l'ordinateur

    // Parcourir les cartes de l'ordinateur et afficher le dos de la carte (image de dos)
    for (int i = 0; i < computerCards.size(); ++i) {
        QPixmap cardBack(":/images/dos/dos.jpg"); // Remplacez avec l'image du dos de la carte
        // Assurez-vous que computerCards[i] représente le QLabel pour la carte actuelle
        computerCards[i]->setPixmap(cardBack); // Afficher le dos de la carte sur le QLabel
        computerCards[i]->setVisible(true); // Rendre la carte visible
    }
}


void MainWindow::updateMiddleCardVisible() {
    // Mettre à jour l'interface pour montrer la carte au milieu (face visible)
    // ...
}

void MainWindow::startGame() {
    // Implémenter les règles du jeu ici
    // ...
}
