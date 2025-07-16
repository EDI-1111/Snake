#include <iostream>
#include <string>
#include <iomanip>
#define NOMINMAX
#include <windows.h>
#include <stdio.h>
#include <conio.h>
#include <random>
#include <vector>
#include <future>
#include <chrono>

using namespace std;


//Struckt object für Positionskoordinaten
struct Position
{
    int x, y;
};

//Funktionen

void EdiTag()
{
    int abstandRand = 2;

    system("chcp 437");
    system("cls");
    cout << "\n\n\n\n\n";
    cout << "powerd by\n";
    cout << setfill(' ') << setw(abstandRand) << "" << setfill('\xDB') << setw(6) << "" << setfill(' ') << setw(3) << "" << setfill('\xDB') << setw(4) << "" << setfill(' ') << setw(5) << "" << setfill('\xDB') << setw(2) << "" << endl;
    cout << setfill(' ') << setw(abstandRand) << "" << setfill('\xDB') << setw(6) << "" << setfill(' ') << setw(3) << "" << setfill('\xDB') << setw(5) << "" << setfill(' ') << setw(4) << "" << setfill('\xDB') << setw(2) << "" << endl;
    cout << setfill(' ') << setw(abstandRand) << "" << setfill('\xDB') << setw(2) << "" << setfill(' ') << setw(7) << "" << setfill('\xDB') << setw(2) << "" << setfill(' ') << setw(2) << "" << setfill('\xDB') << setw(2) << "" << setfill(' ') << setw(3) << "" << setfill('\xDB') << setw(2) << "" << endl;
    cout << setfill(' ') << setw(abstandRand) << "" << setfill('\xDB') << setw(2) << "" << setfill(' ') << setw(7) << "" << setfill('\xDB') << setw(2) << "" << setfill(' ') << setw(2) << "" << setfill('\xDB') << setw(2) << "" << setfill(' ') << setw(3) << "" << setfill('\xDB') << setw(2) << "" << endl;
    cout << setfill(' ') << setw(abstandRand) << "" << setfill('\xDB') << setw(6) << "" << setfill(' ') << setw(3) << "" << setfill('\xDB') << setw(2) << "" << setfill(' ') << setw(2) << "" << setfill('\xDB') << setw(2) << "" << setfill(' ') << setw(3) << "" << setfill('\xDB') << setw(2) << "" << endl;
    cout << setfill(' ') << setw(abstandRand) << "" << setfill('\xDB') << setw(6) << "" << setfill(' ') << setw(3) << "" << setfill('\xDB') << setw(2) << "" << setfill(' ') << setw(2) << "" << setfill('\xDB') << setw(2) << "" << setfill(' ') << setw(3) << "" << setfill('\xDB') << setw(2) << "" << endl;
    cout << setfill(' ') << setw(abstandRand) << "" << setfill('\xDB') << setw(2) << "" << setfill(' ') << setw(7) << "" << setfill('\xDB') << setw(2) << "" << setfill(' ') << setw(2) << "" << setfill('\xDB') << setw(2) << "" << setfill(' ') << setw(3) << "" << setfill('\xDB') << setw(2) << "" << endl;
    cout << setfill(' ') << setw(abstandRand) << "" << setfill('\xDB') << setw(2) << "" << setfill(' ') << setw(7) << "" << setfill('\xDB') << setw(2) << "" << setfill(' ') << setw(2) << "" << setfill('\xDB') << setw(2) << "" << setfill(' ') << setw(3) << "" << setfill('\xDB') << setw(2) << "" << endl;
    cout << setfill(' ') << setw(abstandRand) << "" << setfill('\xDB') << setw(6) << "" << setfill(' ') << setw(3) << "" << setfill('\xDB') << setw(5) << "" << setfill(' ') << setw(4) << "" << setfill('\xDB') << setw(2) << "" << endl;
    cout << setfill(' ') << setw(abstandRand) << "" << setfill('\xDB') << setw(6) << "" << setfill(' ') << setw(3) << "" << setfill('\xDB') << setw(4) << "" << setfill(' ') << setw(5) << "" << setfill('\xDB') << setw(2) << "" << endl;
    cout << "\n\n\n\n\n";
    system("Pause");
}

void FensterGroeße()
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFOEX csbi;
    csbi.cbSize = sizeof(CONSOLE_SCREEN_BUFFER_INFOEX);

    HWND console = GetConsoleWindow();
    RECT r;

    GetWindowRect(console, &r);
    MoveWindow(console, r.left, r.top, 590, 400, TRUE);

    if (!GetConsoleScreenBufferInfoEx(hConsole, &csbi))
    {
        cout << "Fehler beim Abrufen der Konsoleninformationen." << endl;
        return;
    }

    COORD coord = { 50, 23 };

    if (!SetConsoleScreenBufferSize(hConsole, coord))
    {
        cout << "Fehler beim Setzen der Puffergröße." << endl;
        return;
    }


    SMALL_RECT rect;
    rect.Left = 0;
    rect.Right = 49;
    rect.Top = 0;
    rect.Bottom = 22;

    if (!SetConsoleWindowInfo(hConsole, TRUE, &rect))
    {
        cout << "Fehler bei der Fenstergrößenanpassung!" << endl;
    }
}

void FixiereFensterGroesse()
{
    HWND console = GetConsoleWindow();
    if (console == NULL)
    {
        cout << "Fehler: Konsole nicht gefunden!" << endl;
        return;
    }


    // Aktuelle Größe abrufen
    RECT rect;
    GetWindowRect(console, &rect);

    // Fenstergröße festlegen
    SetWindowLong(console, GWL_STYLE,
        GetWindowLong(console, GWL_STYLE) &
        ~(WS_SIZEBOX | WS_MAXIMIZEBOX | WS_THICKFRAME));

    // Fenster auf aktuellen Standort und Größe setzen
    MoveWindow(console,
        rect.left,
        rect.top,
        rect.right - rect.left,
        rect.bottom - rect.top,
        SWP_NOMOVE | SWP_NOSIZE | SWP_NOZORDER);

    // Zusätzliche Sicherheit
    SetWindowPos(console,
        HWND_NOTOPMOST,
        rect.left,
        rect.top,
        rect.right - rect.left,
        rect.bottom - rect.top,
        SWP_NOMOVE | SWP_NOSIZE | SWP_NOZORDER);
}

void hideConsoleCursor(bool hide = true)
{
    CONSOLE_CURSOR_INFO cursorInfo;
    GetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursorInfo);
    cursorInfo.bVisible = !hide;
    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursorInfo);
}
//Tasten Abfrage
void checkArrowKeys(int* arrowKey, Position& richtung)
{
    if (_kbhit())
    {
        int eingabe = _getch();
        if (eingabe == 0 || eingabe == 224) {
            // Sondertasten wie Pfeiltasten liefern zwei Werte
            *arrowKey = _getch();

            switch (*arrowKey)
            {
                //Bewegung Nach Oben
            case 72:
                if (richtung.x != 1)
                {
                    richtung.x = -1;
                    richtung.y = 0;
                }
                break;

                //Bewegung Nach Links
            case 75:
                if (richtung.y != 1)
                {
                    richtung.x = 0;
                    richtung.y = -1;
                }
                break;

                //Bewegung Nach Rechts
            case 77:
                if (richtung.y != -1)
                {
                    richtung.x = 0;
                    richtung.y = 1;
                }
                break;

                //Bewegung Nach Unten
            case 80:
                if (richtung.x != -1)
                {
                    richtung.x = 1;
                    richtung.y = 0;
                }
                break;
            }
        }
    }
}

void Spielfeldbefüllen(string spielfeld[22][50])
{
    for (int i = 0; i < 22; i++)
    {
        for (int j = 0; j < 50; j++)
        {
            spielfeld[i][j] = " ";
        }
    }
}

void SpielfeldRahmenErzeugen(string spielfeld[22][50])
{
    for (int i = 0; i < 22; i++)
    {
        for (int j = 0; j < 50; j++)
        {
            if (i == 0 || i <= 22 && j == 0 || i <= 22 && j == 49 || i == 21)
            {
                spielfeld[i][j] = "#";
            }
        }
    }
}

void SpielfeldAnzeigen(string spielfeld[22][50])
{
    for (int i = 0; i < 22; i++)
    {
        for (int j = 0; j < 50; j++)
        {
            cout << spielfeld[i][j];
        }
        cout << endl;
    }
}

void DeleteSnake(Position last, vector<Position>& snake, string spielfeld[22][50])
{
    //zeichen im Spielfeld löschen
    spielfeld[last.x][last.y] = " ";

    // Zu Position (y,x)
    printf("\033[%d;%dH", last.x + 1, last.y + 1);

    //Zeichen in der Console überschreiben
    cout << " ";
}

void CreateSnake(vector<Position>& snake)
{
    //Start Position der Schlange
    snake.push_back({ 9,25 });
    snake.push_back({ 10,25 });
    snake.push_back({ 11,25 });
}

void AddSnake(vector<Position>& snake, Position last)
{
    snake.push_back({ last.x,last.y });
}

void eateble(int hoehe, int breite, Position& eat, string spielfeld[22][50])
{
    if (eat.x == 0 && eat.y == 0)
    {
        // initialisierung des seeds und befüllung des zufallsgenerators
        random_device x;
        mt19937 gen1(x());
        uniform_real_distribution<> distrib1(2, hoehe - 1);
        // Generiere eine Zufallszahl
        eat.x = distrib1(gen1);

        // initialisierung des seeds und befüllung des zufallsgenerators
        random_device y;
        mt19937 gen2(y());
        uniform_real_distribution<> distrib2(2, breite - 1);
        // Generiere eine Zufallszahl
        eat.y = distrib2(gen2);

        // es wird ein "+" in das Spielfeld Array auf der angegebenen Koordinate gesetzt
        spielfeld[eat.x][eat.y] = "+";

        // Zu Position (x,y)
        printf("\033[%d;%dH", eat.x + 1, eat.y + 1);

        // zeichnen des Zeichens
        cout << "+";
    }
}

void PrintSnake(vector<Position> snake, string spielfeld[22][50])
{
    //Schlange Zeichnen
    for (size_t i = 0; i < snake.size(); i++)
    {
        spielfeld[snake[i].x][snake[i].y] = "*";
        // Zu Position (y,x)
        printf("\033[%d;%dH", snake[i].x + 1, snake[i].y + 1);

        //zeichnen des Zeichens
        cout << "*";
    }
}

void MoveSnake(vector<Position>& snake, Position richtung, Position& last, Position& alt, Position& neu, string spielfeld[22][50])
{
    for (size_t i = 0; i < snake.size(); i++)
    {
        // Abfrage ob die Schleife den letzten Teil der Schlange erreicht hat
        if (i == snake.size() - 1)
        {
            last.x = snake[i].x;
            last.y = snake[i].y;
        }

        // Kopf Der Schlange
        if (i == 0)
        {
            // Alte Position Speichern
            alt.x = snake[i].x;
            alt.y = snake[i].y;

            // Neu Position Setzen
            snake[i].x += richtung.x;
            snake[i].y += richtung.y;
        }
        // Rest der Schlange
        else
        {
            //übergabe alte Position auf neue
            neu.x = alt.x;
            neu.y = alt.y;

            // Alte Position Speichern für alle nachfolgenden Teile der Schlange
            alt.x = snake[i].x;
            alt.y = snake[i].y;

            // Neue Position wird gesetzt
            snake[i].x = neu.x;
            snake[i].y = neu.y;

            // Alt wird nicht benutzt
        }
    }
    // Neu Schlange wird gemalt
    PrintSnake(snake, spielfeld);
    // letztes Element der Schlange wird gelöscht
    DeleteSnake(last, snake, spielfeld);
}

void Score(int& Points)
{
    Points += 10;
    printf("\033[%d;%dH", 23, 1);
    cout << "Punkte: " << Points;
}

void GameOver()
{
    printf("\033[%d;%dH", 11, 20);
    cout << "Game Over\n";
    printf("\033[%d;%dH", 13, 7);
    system("PAUSE");
}

void MenuAnzeigen()
{
    system("cls");
    //Spielfeld Rahmen
    for (int i = 0; i < 22; i++)
    {
        for (int j = 0; j < 50; j++)
        {
            if (i == 0 || i == 21 || j == 0 || j == 49)
            {
                //Position Setzen
                printf("\033[%d;%dH", i + 1, j + 1);

                //Zeichen setzen
                cout << "#";
            }
        }
    }

    for (int i = 0; i < 20; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            if (i == 0 || i == 19 || j == 0 || j == 8)
            {
                //Position Setzen
                printf("\033[%d;%dH", j + 7, i + 16);

                //Zeichen setzen
                cout << "#";
            }
        }
    }

    //Position Setzen
    printf("\033[%d;%dH", 9, 23);
    //Zeichen setzen
    cout << "Snake";

    //Position Setzen
    printf("\033[%d;%dH", 11, 21);
    //Zeichen setzen
    cout << "1. Spielen";

    //Position Setzen
    printf("\033[%d;%dH", 13, 21);
    //Zeichen setzen
    cout << "2. Beenden";
}

int getHiddenInput()
{
    return _getch();
}

int MenuEingabe() {

    int auswahl = _getch();

    while (auswahl < '1' || auswahl > '2') {
        auswahl = _getch();
    }

    return auswahl - '0';  // ASCII-Wert in Zahl umwandeln
}

void MenuSnake2(string spielfeld[22][50], vector<Position>& snake, Position richtung, Position& last, Position& alt, Position& neu)
{
    if (snake[0].x == 4)
    {
        richtung.x = 0;
        richtung.y = -1;
    }
    if (snake[0].y == 3)
    {
        richtung.x = -1;
        richtung.y = 0;
    }
    if (snake[0].x == 2)
    {
        richtung.x = 0;
        richtung.y = 1;
    }
    if (snake[0].y == 45)
    {
        richtung.x = 1;
        richtung.y = 0;
    }
    if (snake[0].x == 19)
    {
        richtung.x = 0;
        richtung.y = -1;
    }
    if (snake[0].y == 40 && snake[0].x > 10)
    {
        richtung.x = -1;
        richtung.y = 0;
    }


    MoveSnake(snake, richtung, last, alt, neu, spielfeld);
}

void MenuSnake1(string spielfeld[22][50], vector<Position>& snake, Position richtung, Position& last, Position& alt, Position& neu)
{
    if (snake[0].x == 10)
    {
        //nach Links
        richtung.x = 0;
        richtung.y = -1;
    }
    if (snake[0].y == 3)
    {
        richtung.x = -1;
        richtung.y = 0;
    }
    if (snake[0].x == 5)
    {
        richtung.x = 0;
        richtung.y = 1;
    }
    if (snake[0].y == 10)
    {
        richtung.x = 1;
        richtung.y = 0;
    }
    if (snake[0].x == 17)
    {
        richtung.x = 0;
        richtung.y = 1;
    }
    if (snake[0].y == 35)
    {
        richtung.x = 1;
        richtung.y = 0;
    }
    if (snake[0].x == 18)
    {
        richtung.x = 0;
        richtung.y = -1;
    }
    if (snake[0].y == 8 && snake[0].x > 10)
    {
        richtung.x = -1;
        richtung.y = 0;
    }
    MoveSnake(snake, richtung, last, alt, neu, spielfeld);
}

bool CheckCollision(string spielfeld[22][50], vector<Position>& snake, Position richtung, Position& last, Position& alt, Position& neu, Position& eat, int& Points, int Hoehe, int Breite)
{
    // abfrage welche Richtung
    // nur die momentane Richtung wird geprüft
    int x = snake[0].x;
    x += richtung.x;

    int y = snake[0].y;
    y += richtung.y;

    // Überprüfen ob Wand oder Schlange in Bewegung´s Richtung ist.
    if (spielfeld[x][y] == "#" || spielfeld[x][y] == "*")
    {
        // Game Over Tag
        // Aufruf Funktion zum Abbruch des Spiels
        GameOver();

        EdiTag();

        // setzt den Bool wert für die endlos Schleife auf False
        return false;
    }
    // Überprüft ob etwas zum Fressen auf dem nächsten Feld ist
    if (spielfeld[x][y] == "+")
    {
        // der Schlange einen weiteren Punkt hinzufügen
        // Nach dem bewegen (dabei) die letzten Koordinaten dem Vector anfügen
        // Aufruf AddSnake
        AddSnake(snake, last);
        spielfeld[x][y] = " ";
        eat.x = 0;
        eat.y = 0;
        Score(Points);
        // Bewegung ausführen
        MoveSnake(snake, richtung, last, alt, neu, spielfeld);
    }
    else
    {
        // Bewegung ausführen
        MoveSnake(snake, richtung, last, alt, neu, spielfeld);
    }
}

void Game(string spielfeld[22][50], int Hoehe, int Breite)
{

    int Points = 0;

    // Koordinaten für essbares
    Position eat;
    eat.x = 0;
    eat.y = 0;

    // separate Position´s Koordinaten
    Position alt;
    Position neu;
    Position last;
    last.x = 0;
    last.y = 0;

    // Behälter für die Richtungsangaben
    // x = 1 // Bewegung nach unten
    // x = 0 // keine Bewegung
    // x = -1 // Bewegung nach Oben
    // y = 1 // Bewegung nach rechts 
    // y = 0 // keine Bewegung
    // y = -1 // Bewegung nach links
    Position richtung;
    // Start Richtung
    richtung.x = -1;
    richtung.y = 0;

    // variable für die Tasteneingabe
    int arrowkey = 0;

    // Bool wert für EndlosSchleife
    bool collision = true;

    // Leerer Dynamischer Behälter für die Schlange
    vector<Position> snake;

    Spielfeldbefüllen(spielfeld);
    SpielfeldRahmenErzeugen(spielfeld);

    // Löscht das gesamte Bild der Konsole
    system("cls");

    // Mahlt den Spielfeldrand 
    SpielfeldAnzeigen(spielfeld);

    // erzeugt Schlange
    CreateSnake(snake);

    // Endlos Schleife
    while (collision)
    {

        // Warte Zeit in Millisekunden 
        Sleep(300);

        // Funktions Aufruf Tasten Abfrage
        checkArrowKeys(&arrowkey, richtung);

        // Kollisionsabfrage
        collision = CheckCollision(spielfeld, snake, richtung, last, alt, neu, eat, Points, Hoehe, Breite);
        eateble(Hoehe, Breite, eat, spielfeld);
    }
}

void MainMenu(string spielfeld[22][50], int Hoehe, int Breite)
{
    //Schlange und Anfangsposition
    vector<Position> snakeMenu1;
    snakeMenu1.push_back({ 15,8 });
    snakeMenu1.push_back({ 16,8 });
    snakeMenu1.push_back({ 17,8 });
    snakeMenu1.push_back({ 18,8 });
    snakeMenu1.push_back({ 19,8 });

    // Behälter für die Richtungsangaben für die Menu Schlangen
    Position richtungMenuSnake1;

    //Anfangs bewegungsrichtung für die Menu Schlangen
    richtungMenuSnake1.x = -1;
    richtungMenuSnake1.y = 0;

    // separate Position´s Koordinaten
    Position MenuSnakeAlt1;
    Position MenuSnakeNeu1;
    Position MenuSnakeLast1;

    //Schlange und Anfangsposition
    vector<Position> snakeMenu2;

    //Start Position der Schlange
    snakeMenu2.push_back({ 5,40 });
    snakeMenu2.push_back({ 6,40 });
    snakeMenu2.push_back({ 7,40 });
    snakeMenu2.push_back({ 8,40 });
    snakeMenu2.push_back({ 9,40 });

    // Behälter für die Richtungsangaben für die Menu Schlangen
    Position richtungMenuSnake2;

    //Anfangs bewegungsrichtung für die Menu Schlangen
    richtungMenuSnake2.x = -1;
    richtungMenuSnake2.y = 0;

    // separate Position´s Koordinaten
    Position MenuSnakeAlt2;
    Position MenuSnakeNeu2;
    Position MenuSnakeLast2;

    //Menu Anzeigen
    MenuAnzeigen();

    // Thread für Eingabe erstellen
    future<int> eingabe = async(launch::async, MenuEingabe);

    // Hauptthread läuft weiter
    while (eingabe.wait_for(chrono::milliseconds(250)) != future_status::ready)
    {

        MenuSnake1(spielfeld, snakeMenu1, richtungMenuSnake1, MenuSnakeLast1, MenuSnakeAlt1, MenuSnakeNeu1);
        MenuSnake2(spielfeld, snakeMenu2, richtungMenuSnake2, MenuSnakeLast2, MenuSnakeAlt2, MenuSnakeNeu2);
    }

    // wartet bis thread Eingabe zuende ist
    int ergebnis = eingabe.get();
    if (ergebnis == 1)
    {
        Game(spielfeld, Hoehe, Breite);
    }
    if (ergebnis == 2)
    {
        EdiTag();
        return;
    }
}

int main()
{
    FensterGroeße();

    hideConsoleCursor(true);
    // Spielfeld Variablen für die Größe
    const int Hoehe = 22;
    const int Breite = 50;

    // Spielfeld Leer
    string spielfeld[Hoehe][Breite];


    // Vector Behälter für Essbares
    vector<Position> eatList;
    eatList.push_back({ 5,5 });
    eatList.push_back({ 3,35 });
    eatList.push_back({ 15,5 });
    eatList.push_back({ 25,38 });
    eatList.push_back({ 35,25 });



    MainMenu(spielfeld, Hoehe, Breite);


    return 0;
}