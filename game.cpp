#include <iostream>

using namespace std;



class player
{
  private:
  int HP;
  int ATK;
  int BLK;
  int P_NUMBER;

  public:
    player(int _hp, int _atk, int _blk, int _pn){
      HP = _hp;
      ATK = _atk;
      BLK = _blk;
      P_NUMBER = _pn;
    }
    int getHP(){return HP;}
    void setHP(int _hp){HP = _hp;}

    int getATK(){return ATK;}
    void setATK(int _atk){ATK = _atk;}

    int getBLK(){return BLK;}
    void setBLK(int _blk){BLK = _blk;}

    int getP_NUMBER(){return P_NUMBER;}
    void setP_NUMBER(int _pn){P_NUMBER = _pn;}
};


int main()
{

  player player1(10, 2, 0, 3);
  player player2(10, 2, 0, 3);




 int turn = 1;
 int potionSTR = 3;
 char player1Moove;
 char player2Moove;
 int block1 = 0;
 int block2 = 0;




 while(player1.getHP() > 0 && player2.getHP() > 0)
     {
       cout << "Player 1's HP: " << player1.getHP() << endl;
       cout << "Player 2's HP: " << player2.getHP() << endl;
       cout << endl;

       if(turn == 1)
       {
         cout << "Player 1's turn" << endl;
         cout << player1.getP_NUMBER() << " potions left" << endl;
         cout << "A = Attack, P = Potion, B = Block: ";



         cin >> player1Moove;
         cout << "-------------------------------------" << endl;

         if(player1Moove == 'a')
         {
           player2.setHP((player2.getHP() - player1.getATK()) + player2.getBLK());
           if(player2.getHP() <= 0)
           {
             player2.setHP(0);
           }
           turn = 2;
         }
         else if(player1Moove == 'p')
         {
           if (player1.getP_NUMBER() > 0)
           {
           player1.setHP(player1.getHP() + potionSTR);
           player1.setP_NUMBER(player1.getP_NUMBER() - 1) ;
           }
           if (player1.getP_NUMBER() <= 0)
           {
             player1.setP_NUMBER(0);
           }
           if(player1.getHP() >= 10)
           {
             player1.setHP(10);
           }
           turn = 2;
         }
         else if(player1Moove == 'b')
       {
         player1.setBLK(1);
         turn = 2;
       }
       else
         {
           turn = 2;

         }
           player2.setBLK(0);
       }

       else
         {
           cout << "Player 2's turn" << endl;
           cout << player2.getP_NUMBER() << " potions left" << endl;
           cout << "A = Attack, P = Potion, B = Block: ";


           cin >> player2Moove;
           cout << "-------------------------------------" << endl;

           if (player2Moove == 'a')
           {
             player1.setHP((player1.getHP() - player2.getATK()) + player1.getBLK());

                if (player1.getHP() <= 0)
             {
               player1.setHP(0);
             }
             turn = 1;
           }
             else if (player2Moove == 'p')
             {
               if (player2.getP_NUMBER() > 0)
               {
               player2.setHP(player2.getHP() + potionSTR);
               player2.setP_NUMBER(player2.getP_NUMBER() - 1) ;
               }
               if (player2.getP_NUMBER() <= 0)
               {
                 player2.setP_NUMBER(0);
               }

                  if(player2.getHP() >= 10)
               {
                 player2.setHP(10);
               }
               turn = 1;
              }
              else if (player2Moove == 'b')
              {
                player2.setBLK(1);
                turn = 1;
              }

              else
              {
                turn = 1;

              }
              player1.setBLK(0);
           }
         }


         if (player1.getHP() == 0)
         {
           cout << "Player 1's HP: " << player1.getHP() << endl;
           cout << "Player 2's HP: " << player2.getHP() << endl;
           cout << "Player 2 is the WINNER!" << endl;
         }

         if (player2.getHP() == 0)
         {
           cout << "Player 1's HP: " << player1.getHP() << endl;
           cout << "Player 2's HP: " << player2.getHP() << endl;
           cout << "Player 1 is the WINNER!" << endl;
         }

         return 0;
 }
