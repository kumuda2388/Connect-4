#include<iostream>
#include <string>
#include<fstream>
#include<stdlib.h>
#include<windows.h>
using namespace std;
void gotoxy(short x, short y);
void Start_game();
void How_to_play();
void About_the_game();
void High_Scores();
void display();
char board[6][7];//6*7 connect4 game board
void connect_main();
int register_count=0;
class connect4
{
int colChoice;
char player;
int hold2;
public:
	connect4(){ hold2=0;
	}
int connect_4(char p1[30],char p2[30]);
friend int drop_coin(connect4 oj2,int a, char b);
friend bool check(connect4 oj2,int hold2, int colChoice);
};
connect4 o2;
int main()
{
int choice;
    string
    command, //to choose what to do each time
    name, password, //the ones that are found in the file
    inName, inPassword, //the ones you are going to input from keyboard
    registerName, registerPassword; //also what you're going to input and if you know C strings, just replace that with something like
    int i=0,register_count_n;
    do
    {
        system("cls");
        gotoxy(90,1);cout<<"Welcome to CONNECT-4"<<endl;
         cout<<"Please register if it's your first time"<<endl;
         cout<<"Enter the task that you want to perform";
        cout<<endl<<"Sign Up"<<endl<<"Login"<<endl<<"Exit"<<endl<<endl;
         cout<<"Enter the Command: ";
        getline(cin, command);
        system("cls");
        if (command=="Sign Up")
        {
            //open file for registration
            ofstream g("registration.txt",ios::app); //ofstream is the one for getting data from the file,and the file does not even have to exist. If it's ofstream, it'll take care of it for you.
            //but be warned that if there is a file called "registration.txt" in the name folder as the .exe file, the contents will be appened in this case.
            if (!g.is_open()) //if it's not open, then there is no such file with the given name inside the folder (that is, in the folder where the .exe file is going to be)
            {
                cout<<"could not open file\n"; //just so that you know why it won't work if it doesn't
                return 0;
            }
            cout<<"New Username: ";
            getline(cin, registerName); //input from keyboard will go into registerName
            cout<<"New Password: ";
            getline(cin, registerPassword); //input from keyboard will go into registerPassword
            g<<registerName; //this basically says "put whatever's to the right (registerName) into g ("registration.txt")".
            g<<'\n'; //and now there will be a new line
            g<<registerPassword; //and now the password all placed safely in the file that g opened
            g<<'\n';
            g.close(); //always make sure you close the file, or else you might end up with some nasty stuff in the memory
           ifstream rc("no_of_registrations.txt");
           rc>>register_count_n;
		   register_count=register_count_n+1;
		   rc.close();
		   ofstream rc_feed("no_of_registrations.txt");
		   rc_feed<<register_count;
		   rc_feed.close();
        }
        if (command=="Login") //(for C strings) if (!strcmp(command, "login"))
        {
            //open file, and then put the name and password into the strings
            ifstream f("registration.txt"); //ifstream is the one for getting data from the file, and let us assume you've already created a file called "registration.txt"
            ifstream rc("no_of_registrations.txt");
            rc>>register_count_n;
            rc.close();
            if (!f.is_open()) //if it's not open, then there is no such file with the given name inside the folder (that is, in the folder where the .exe file is going to be)
            {
                cout<<"could not open file\n"; //just so that you know why it won't work if it doesn't
                return 0;
            }
            getline(f, name, '\n'); //reads the user name from file f (which is using "registration.txt")
            getline(f, password, '\n'); //reads the password from file f (which is using "registration.txt")
                                                //also, if you tell the file to get you that text up until '\n', that's when you know it reads
                                                //the whole line at most, and won't go any further and that is done by the 3rd parameter//login

                system("cls");
                    cout<<"Enter Username: ";
                getline(cin, inName);
                cout<<"Enter Password: ";
                getline(cin, inPassword);  //or this, if you are working with C strings (second version of declaration)
                system("cls");
                do{
                if (inName==name && inPassword==password)
                {
                   connect_main();
                    break; //just exit the while loop if you've entered the valid account
                }
				getline(f, name, '\n'); //reads the user name from file f (which is using "registration.txt")
                getline(f, password, '\n'); //reads the password from file f (which is using "registration.txt")
                i++;                                //also, if you tell the file to get you that text up until '\n', that's when you know it reads
                                                //the whole line at most, and won't go any further and that is done by the 3rd parameter
				}while(i!=register_count_n);
                cout<<"incorrect name or password\n"; //if you haven't entered the valid account,
                system("pause");

                f.close(); //you don't need it open now, since you have the name and password from the file
			}

	       cout<<"\n\n\n\n\n"; //give it 5 newlines
    }while(command!="Exit");
return 0;
}
void connect_main()
{    int choice;
	cout<<"Login Successful\n" //the '\n' is a character, so that's why I can add it and it will automatically output a newline in console, alongside the string
                        <<"Welcome to connect 4 ";
                         cout<<endl;
                        system("pause");

do
{
system("cls");
gotoxy(90,1);cout<<"WELCOME TO CONNECT-4 Game";
cout<< "\n 1 - Start the game.\n";
cout<< "\n 2 - About the game .\n";
cout<< "\n 3 - How to play.\n";
cout<< "\n 4- Exit.\n";
cout<< "\n Enter your choice and press return: \n";
cin >> choice;

switch (choice)
{
case 1:Start_game();
	//code to start the game.
break;
case 2:About_the_game();
	//About the game.
break;
case 3:How_to_play();
	//code on how to play.
break;
case 4:
	//Quit the program.
system("cls");
cout << "End of Program.\n";
system("pause");
exit(0);
break;
default:
cout<< "Not a Valid Choice. \n";
cout<< "Choose again.\n";
break;
}

}while(choice!=4);
}
//void Start_game
void Start_game()
 {
 	system("cls");
	int ch;
	gotoxy(90,1);cout<<"CONNECT 4"<<endl;
	cout<<"Enter your choice of the game:"<<endl;
	cout<<"1.  Play with another player"<<endl;
	cin>>ch;
	char playername1[30],playername2[30];
	if(ch==1)
	   {
	       system("cls");
	        cout<<"Connect_4"<<endl;
	    cout<<"enter player 1 name:";
	    cin>>playername1;//taking name of players
	         cout<<"enter player 2 name:";
	    cin>>playername2;//taking name of players
	    cout<<playername1<<"is assigned with the token "<<char(254)<<endl;
    	cout<<playername2<<"is assigned with the token "<<char('o')<<endl;
    o2.connect_4(playername1,playername2);
    	}
	else if(ch==2)
	    {
	    	cout<<"connect_4"<<endl;
	     cout<<"enter player 1 name:"<<endl;
	    cin>>playername1;//taking name of players
		}
	else
	    {
	    	cout<<"The choice you entered is incorrect";
			 }
}

/*void About the game */
void About_the_game()
{
		system("cls");
		gotoxy(90,1);cout<<"ABOUT CONNECT-4";
	cout<<"\n CONNECT 4 is a two-player connection game in which the players first choose a colour and then take turns dropping one coloured disc from the top into a seven-column, six-row vertically suspended grid.";
	cout<<"\n The pieces fall straight down, occupying the lowest available space within the column.";
	cout<<"\n The objective of the game is to be the first to form a horizontal, vertical, or diagonal line of four of one's own discs.";
	cout<<"\n The game was first known as THE CAPTAIN'S MISTRESS, but was released in its current form by Milton Bradley in 1974.";
	cout<<"\n In 1988 Victor Allis solved the game, showing that with perfect play by both players, the first player can always win if he plays the middle column first.";
	cout<<"\n And if he chooses another column first the second player can always force a draw.";
    cout<<endl;

system("pause");
}

//void How to play
void How_to_play()
{
		system("cls");
	gotoxy(90,1);cout<<"HOW TO PLAY";
	cout<<"\n  1.   Type the coloumn number you want a disk to drop. \n";
	cout<<"\n  2.   Connect the 4 tiles of your disk type in a --VERTICAL or HORIZONTAL or DIAGONAL line\n";
	cout<<"\n  3.   The first player to get four of their disk type  either vertically or horizontally or diagonally wins the game.\n";
cout<<endl;
system("pause");
}

    //FUNCTION-To display the board
    void display()
    {
		system("cls");
        gotoxy(90,1);cout<<"CONNECT 4"<<endl;
        cout<<" 1   2   3   4   5   6   7\n";
        for(int r = 0; r<= 5; r++)//r=row number
            {
                //c=column number
                for(int c=0; c <7; c++)
                    cout<<char(218)<<char(196)<<char(191)<<" ";
                cout<<'\n';
                for(int c =0; c<7; c++)
                    cout<<char(179)<<board[r][c]<<char(179)<<" ";
                cout<<'\n';
                for(int c =0; c <7; c++)
                    cout<<char(192)<<char(196)<<char(217)<<" ";
                cout<<'\n';
            }
    }
int connect4::connect_4(char p1[30],char p2[30])
{

	system("cls");
    cout<<"CONNECT 4"<<endl;
    	system("cls");
    cout<<"CONNECT 4"<<endl;
    //Displays the board for the first time so that the players can see them
    //to fill the board with blank spaces
    for(int r =0;r<6; r++)
    {
        for(int c= 0; c<7; c++)
			board[r][c] = ' ';
    }
    display();//Displays the board for the first time so that the players can see them
    system("pause");
	//int colChoice;//Will hold the value of the player's choice of row
	//int hold2 = 0;//will hold drop value
	int boardFull = 0;//Number of pieces dropped (To check if board has 42 coins to declare draw)
	bool gamewon = false;//Will be changed to true when game is won and will exit the while loop
	char player ='o';
	while(!gamewon){//will stop when game is won
		if(hold2 != -1){//check if there was a error in the last drop
			if(player == 'o'){//if player 2 dropped a coin last, it's player 1's turn
				cout<<"Player "<<p1<<"\'s turn. Enter the column into which you wish to drop the coin: ";
				player = 254;//character representing player 1's coin
			}
			else{
				cout<<"Player "<<p2<<"\'s turn. Enter the column into which you wish to drop the coin: ";
				player = 'o';//character representing player 2's coin
			}
		}
		while(true)//will run until the break statement is encountered
		{
			if(boardFull == 42)
                break;//if draw
			cin>>colChoice;//get player's row of choice
			colChoice--;//array index starts from 0, Thus, decrement 1.
			if(colChoice <7 && colChoice>= 0)
                break;//if within valid range stop loop
			else cout<< "\nPlease enter a value between 1 and 7 : ";//ask for input and loop again
		if (cin.fail())	//catch a non number
			{
			    try
			    {
			        cout<<"error!it is a character."<<endl;
			        throw colChoice;
			    }				
			    catch(...) //Catch a non number
			    {
				cin.clear();		//Stops cin trying to put its value in to hold
				char c;		
				cin>>c;			
			}
				}	

		}
		if(boardFull == 42) break;//if draw
		hold2 = drop_coin(o2,colChoice,player);//drop the player's coin and store it's value in hold2
		if(hold2 == -1)	cout<<"Column is full\nPlease enter another number between 1 and 7: ";//if there is an error, hold2= -1, i.e. row is full
		else{
			gamewon = check(o2,hold2,colChoice);//check if game is won
			boardFull ++;//another coin has been successfully dropped into the board
			system("cls");//clear screen built-in function
			display();//displayed updated board
		}
	}
		system("pause");
	system("cls");

	if(boardFull == 42)//if draw
	{
		cout<<"The game was a draw.\n";
		system("pause");
		return 0;
	}
	//ofstream hs("High_score.txt");

	if(player == 'o')//if won by player 2
	{
	  cout<<"Game won by : "<<p2<<endl;
	}
	else
	{
	  cout<<"Game won by : "<<p1<<endl;//Else won by player 1
	}
    system("pause");//pauses before exiting the program so players can see who won
return 0;
}
bool check(connect4 oj2,int a, int b){
	int vertical = 1;//(|)
	int horizontal = 1;//(-)
	int diagonal1 = 1;//(\)
	int diagonal2 = 1;//(/)
	char player = board[a][b];
	int i;//vertical
	int ii;//horizontal
	//check for vertical(|)
	for(i = a +1;board[i][b] == player && i <6;i++,vertical++);//Check down
	for(i = a -1;board[i][b] == player && i >= 0;i--,vertical++);//Check up
	if(vertical >= 4)
        return true;
	//check for horizontal(-)
	for(ii = b -1;board[a][ii] == player && ii >= 0;ii--,horizontal++);//Check left
	for(ii = b +1;board[a][ii] == player && ii <7;ii++,horizontal++);//Check right
	if(horizontal >= 4)
	 return true;
	//check for diagonal 1 (\)
	for(i = a -1, ii= b -1;board[i][ii] == player && i>=0 && ii >=0; diagonal1 ++, i --, ii --);//up and left
	for(i = a +1, ii = b+1;board[i][ii] == player && i<6 && ii <7;diagonal1 ++, i ++, ii ++);//down and right
	if(diagonal1 >= 4)
	return true;
	//check for diagonal 2(/)
	for(i = a -1, ii= b +1;board[i][ii] == player && i>=0 && ii <= 6; diagonal2 ++, i --, ii ++);//up and right
	for(i = a +1, ii= b -1;board[i][ii] == player && i<=5 && ii >=0; diagonal2 ++, i ++, ii --);//up and left
	if(diagonal2 >= 4)
	return true;
	//If all conditions fail
	return false;
}
int drop_coin(connect4 oj2,int colNo, char player)
{
	if(colNo >=0 && colNo<= 6)
	{
		if(board[0][colNo] == ' ')
            { int i;
                for(i = 0;board[i][colNo] == ' ';i++)
				if(i == 5)
				{
				    board[i][colNo] = player;
				    return i;
                }
			i--;
			board[i][colNo] =player;
			return i;

		}
		else{
			return -1;
		}

	}
	else{
		return -1;
	}

}

void gotoxy(short x, short y)           //definition of gotoxy function//
{
 COORD pos ={x,y};
 SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}