#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int currentCards(int n, int i);
void cardSymbolNums(int n);
void cardSymbolFaces(char face);
char cardFace();
int cardDraw();
char cardColor();
int askBet(int player_bet, int player_money, int banker_money);
int checkBet(int player_bet, int player_money, int banker_money);
int cardValue(int v);
int pick(int v);
int results(int player_hand, int finput, int player_money, int player_bet, int banker_money);
int bankersDraw(int player_bet, int player_money, int player_hand, int banker_bet, int banker_money);
int smartBanker(int banker_hand, int player_hand);
int BankercardValue(int v, int banker_hand);
int Bankerpick(int v, int banker_hand);
int gameover();

int main()
{
    int n, v;
    int game;
    int finput = 0, player_money = 100, player_bet, player_hand = 0;
    int banker_bet, banker_money, banker_hand;
    int value = 0;
    int WinOrLoss;



        printf("-----blackjack-----\n");

        banker_money = player_money;
while ((player_money > 0) && (banker_money > 0))
    {
        player_bet = askBet(player_bet, player_money, banker_money);
        banker_bet = player_bet;
        player_money = player_money - player_bet;
        banker_money = banker_money - banker_bet;
        finput = 1;

    while ((finput != 2))  {

        n = cardDraw();
        v =cardValue(n);

        cardColor();
        player_hand = player_hand + v;

        printf("money: %d\n", player_money);
        printf("card value= %d\n", v);
        printf("total hand value: %d\n", player_hand);
        printf("------\n");

        WinOrLoss = results(player_hand, finput, player_money, player_bet, banker_money);
        if(WinOrLoss == 0)
        {

            player_money = player_money + (2 * player_bet);

            player_hand = 0;
            finput = 2;
        }
        else if ((WinOrLoss == 3) && (player_money == 0))  {

            printf("GAME OVER\n\n");

            player_money = gameover();

            player_hand = 0;
            finput = 2;
}
        else if (WinOrLoss == 3) {

            printf("bust\n\n");

            printf("bankers money: %d\n", player_bet + banker_bet);
            banker_money = banker_money + player_bet + banker_bet;

            player_hand = 0;
            banker_hand = 0;
            finput = 2;
        }
        else if(WinOrLoss == 1)  {

            finput = 1;
        }
        else if(WinOrLoss == 2){

        printf("-----banker-----\n");

        game = bankersDraw(player_bet, player_money, player_hand, banker_bet, banker_money);

        if((game == 1) && (player_money <= 0))
            {

            player_money = 0;
            finput = 2;
        }
        else if(game == 1)
            {

        banker_money = banker_money + banker_bet + player_bet;

        player_hand = 0;
        banker_hand = 0;
        finput = 2;
        }

        else if(game == 2){

        player_money = player_money + banker_bet + player_bet;

        printf("total amount: %d\n", player_money);

        finput = 2;
        player_hand = 0;
        banker_hand = 0;

        }

        else{finput = 2;}

        }
        else{gameover();}
}
    }
    player_money = gameover();

    printf("\n\ngame end\n");

    return 0;
}
int cardDraw() {

int n;

n = 1 + rand() % 13;

    if( (n > 1) && (n <= 10)) {
        printf("\ncard:\n");

        cardSymbolNums(n);
}
    else{cardFace(n);}

return n;
}


// CARD INIT
char cardColor(){

    char* color[5];
    int i;

    i = rand() % 2;

    if(i == 0){
        *color = "black";
    }
    else{*color = "red";}

    printf("%s\n", *color);
}

char cardFace(int card){
    char face;

    if(card == 1){
    face = 'A';
}

    else if(card == 11){
        face = 'J';
}
    else if (card == 12){
        face = 'Q';
}
    else{ face = 'K';}
        cardSymbolFaces(face);
}

void cardSymbolNums(int n){
int face;
face = rand() % 4;
char cardType;

if(face == 0){
    cardType = 'S';
    printf("%d-------\n", n);
    printf("%c       |\n", cardType);
    printf("|       |\n", n);
    printf("|       %c\n", cardType);
    printf(" -------%d\n", n);
}
else if(face == 1){
    cardType = 'D';
    printf("%d-------\n", n);
    printf("%c       |\n", cardType);
    printf("|       |\n", n);
    printf("|       %c\n", cardType);
    printf(" -------%d\n", n);
}
else if(face == 2){
    cardType = 'C';
    printf("%d-------\n", n);
    printf("%c       |\n", cardType);
    printf("|       |\n", n);
    printf("|       %c\n", cardType);
    printf(" -------%d\n", n);
}
else{ cardType = 'H';
    printf("%d-------\n", n);
    printf("%c       |\n", cardType);
    printf("|       |\n", n);
    printf("|       %c\n", cardType);
    printf(" -------%d\n", n);}
}

void cardSymbolFaces(char face){
int type;
type = rand() % 4;
char cardType;

if(type == 0){
    type = 'S';
    printf("%c-------\n", face);
    printf("%c       |\n", type);
    printf("|       |\n", face);
    printf("|       %c\n", type);
    printf(" -------%c\n", face);
}
else if(type == 1){
    type = 'D';
    printf("%c-------\n", face);
    printf("%c       |\n", type);
    printf("|       |\n", face);
    printf("|       %c\n", type);
    printf(" -------%c\n", face);
}
else if(type == 2){
    type = 'C';
    printf("%c-------\n", face);
    printf("%c       |\n", type);
    printf("|       |\n", face);
    printf("|       %c\n", type);
    printf(" -------%c\n", face);
}
else{ type = 'H';
    printf("%c-------\n", face);
    printf("%c       |\n", type);
    printf("|       |\n", face);
    printf("|       %c\n", type);
    printf(" -------%c\n", face);
}
}

int askBet(int player_bet, int player_money, int banker_money) {

    printf("player Money : %d\nbanker Money: %d\n", player_money, banker_money);
    printf("\n\nbet: ");

    scanf("%d", &player_bet);
    player_bet = checkBet(player_bet, player_money, banker_money);

    return player_bet;
}
int checkBet(int player_bet, int player_money, int banker_money){

    if((player_bet > player_money) || (player_bet > banker_money)){
        printf("\nbet error\n");
        askBet(player_bet, player_money, banker_money);
    }
    else{

    return player_bet;
        }
    }

int cardValue(int v){
    if(v >= 10){
        v = 10;
    }
    else if((v >= 2) && (v <= 9)){
        v = v;
    }
    else{v = pick(v);}

    return v;
}

int pick(int v){

    int decision[4];

    printf("ace value: \n");
    scanf("%d", decision);

    if (strcmp(decision, "11") == 0){

        v = 11;
        return v;
}
    else if (strcmp(decision, "1") == 0){

        v = 1;
        return v;
}
}


int results(int player_hand, int finput, int player_money, int player_bet, int banker_money){

int userChoice;

if(player_hand == 21){
    printf("blackjack\n");
    printf("money won: %d\n", (2 * player_bet));
    return 0;
}
else if(player_hand > 21){
    return 3;
}
else if(player_hand < 21){
    printf("\n1 - hit\n2 - stay: ");
    scanf("%d", &finput);
    if((finput == 1)){
    return finput;
    }
    else if(finput == 2){
        return finput;
    }

    results(player_hand, finput, player_money, player_bet, banker_money);
}
}

int bankersDraw(int player_bet, int player_money, int player_hand, int banker_bet, int banker_money){

    int t, u, finish, banker_hand = 0;

    while(banker_hand <= 21){

        t = cardDraw();
        u = BankercardValue(t, banker_hand);
        cardColor();
        banker_hand = banker_hand + u;

        printf("card value is = %d\n", u);
        printf("total hand value: %d\n", banker_hand);

        finish = smartBanker(banker_hand, player_hand);

    if(finish == 1 ){
        return 1;
    }
    else if(finish == 2){
        return 2;
    }
    }
    }

int smartBanker(int banker_hand, int player_hand){
    if((banker_hand > player_hand) && (banker_hand <= 21)){
        printf("bankers victory\n");
        return 1;
    }
    else if(banker_hand <= player_hand){

        return 0;
    }
    else if (banker_hand == player_hand){

        return 0;;
    }
    else if(banker_hand > 21){

        printf("bankers bust\n");
        return 2;
    }
}

int BankercardValue(int v, int banker_hand){
    if(v >= 10){
        v = 10;
    }
    else if((v >= 2) && (v <= 9)){
        v = v;
    }
    else{v = Bankerpick(v, banker_hand);}

    return v;
}

int Bankerpick(int v, int banker_hand){

    printf("ace\n");
    if(banker_hand <= 10){
        v = 11;
        return v;
    }
    else{
        v = 1;
        return v;
    }
}

int gameover(){
    char gameOverDecision;

    int d;

    scanf("%s", gameOverDecision);

    if(strcmp(gameOverDecision, "play again") == 0) {

        printf("play again y or n\n");
        scanf("%d", &d);

        return d;
}
else if (strcmp(gameOverDecision, "n") == 0) {

    return 0;
}
else{printf("error\n");
    gameover();
    }
}

