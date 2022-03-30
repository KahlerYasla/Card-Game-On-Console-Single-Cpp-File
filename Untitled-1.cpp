#include <iostream>
#include <vector>
#include <memory>
#include <cstdlib>
#include <ctime>
#include <windows.h>  
#include <stdlib.h>


class mana {
protected:
    int whiteMana = 1;
    int redMana = 1;
    int greenMana = 1;
    int blueMana = 1;
    int blackMana = 1;
    int colorlessManaSum = whiteMana + redMana + greenMana + blueMana + blackMana;
    std::string cardName;

public:
//Reset mana each turn
    void resetMana(){
        whiteMana = 0;
        redMana = 0;
        greenMana = 0;
        blueMana = 0;
        blackMana = 0;
    }
//Give player's mana information in game
    void printMana(){
        std::cout << "White mana: " << whiteMana << " / " << "Green mana: " << greenMana << " / " << "Blue mana: " << blueMana << " / " <<
                  "Red mana: " << redMana << " / " << "Black mana: " << blackMana << std::endl;
    }

//getMana to get user input mana color
    void getMana() {colorlessManaSum = whiteMana + redMana + greenMana + blueMana + blackMana;
        std::string temp;
        std::cout << "Choose whichever color of mana you want to use " << std::endl;
        std::cout << "R for red / W for white / G for green / L for blue / B for black " << std::endl;
        std::cin >> temp;

        if (temp == "R" && redMana > 0) {
            redMana--;
        } else if (temp == "R" && redMana <= 0) {
            std::cout << "You dont have enough mana. " << std::endl;
            getMana();
        }


        else if (temp == "W" && whiteMana>0) {
            whiteMana--;}
        else if (temp == "W" && whiteMana <= 0) {
            std::cout << "You dont have enough mana. " << std::endl;
            getMana();
        }

        else if (temp == "G"&& greenMana>0) {
            greenMana--;}
        else if (temp == "G" && greenMana <= 0) {
            std::cout << "You dont have enough mana. " << std::endl;
            getMana();
        }

        else if (temp == "L" && blueMana>0) {
            blueMana--;}
        else if (temp == "L" && blueMana <= 0) {
            std::cout << "You dont have enough mana. " << std::endl;
            getMana();
        }

        else if (temp == "B"&&blackMana>0) {
            blackMana--;}
        else if (temp == "B" && blackMana <= 0) {
            std::cout << "You dont have enough mana. " << std::endl;
            getMana();
        }

    }

//Mana cost function
    void cost(std::string c) {colorlessManaSum = whiteMana + redMana + greenMana + blueMana + blackMana;
        cardName = c;

//Creature Cards

        if (cardName == "Soldier") {
            if (whiteMana > 0) {
                whiteMana--;
            } else {
                std::cout << "Not enough mana. " << std::endl;
            }


        } else if (cardName == "ArmoredPegasus") {
            if (whiteMana >= 1 && colorlessManaSum - whiteMana >= 1) {
                whiteMana--;
                getMana();
            } else {
                std::cout << "Not enough mana. " << std::endl;
            }

        } else if (cardName == "WhiteKnight") {
            if (whiteMana >= 2) {
                whiteMana--;
                whiteMana--;
            } else {
                std::cout << "Not enough mana. " << std::endl;
            }

        } else if (cardName == "AngryBear") {
            if (greenMana >= 1 && colorlessManaSum - greenMana >= 2) {
                greenMana--;
                getMana();
                getMana();

            } else {
                std::cout << "Not enough mana. " << std::endl;
            }

        } else if (cardName == "Guard") {
            if (whiteMana >= 2 && colorlessManaSum - whiteMana >= 2) {
                whiteMana--;
                whiteMana--;
                getMana();
                getMana();
            } else {
                std::cout << "Not enough mana. " << std::endl;
            }

        } else if (cardName == "Werewolf") {
            if (whiteMana >= 1 && greenMana >= 1 && colorlessManaSum - whiteMana - greenMana >= 2) {
                greenMana--;
                whiteMana--;
                getMana();
                getMana();
            } else {
                std::cout << "Not enough mana. " << std::endl;
            }

        } else if (cardName == "Skeleton") {
            if (blackMana >= 1) {
                blackMana--;
            } else {
                std::cout << "Not enough mana. " << std::endl;
            }

        } else if (cardName == "Ghost") {
            if (blackMana >= 1 && colorlessManaSum - blackMana >= 1) {
                blackMana--;
                getMana();
            } else {
                std::cout << "Not enough mana. " << std::endl;
            }

        } else if (cardName == "BlackKnight") {
            if (blackMana >= 2) {
                blackMana--;
                blackMana--;
            } else {
                std::cout << "Not enough mana. " << std::endl;
            }

        } else if (cardName == "OrcManiac") {
            if (redMana >= 1 && colorlessManaSum - redMana >= 2) {
                redMana--;
                getMana();
                getMana();
            } else {
                std::cout << "Not enough mana. " << std::endl;
            }

        } else if (cardName == "Hobgoblin") {
            if (redMana >= 1 && blackMana >= 1 && colorlessManaSum - redMana - blackMana >= 1) {
                redMana--;
                blackMana--;
                getMana();
            } else {
                std::cout << "Not enough mana. " << std::endl;
            }

        } else if (cardName == "Vampire") {
            if (blackMana >= 1 && colorlessManaSum - blackMana >= 3) {
                blackMana--;
                getMana();
                getMana();
                getMana();
            } else {
                std::cout << "Not enough mana. " << std::endl;
            }

//Sorcery Cards

        } else if (cardName == "Disenchant") {
            if (whiteMana >= 1 && colorlessManaSum - whiteMana >= 1) {
                whiteMana--;
                getMana();
            } else {
                std::cout << "Not enough mana. " << std::endl;
            }

        } else if (cardName == "LightningBolt") {
            if (greenMana >= 1 && colorlessManaSum - greenMana >= 1) {
                greenMana--;
                getMana();
            } else {
                std::cout << "Not enough mana. " << std::endl;
            }

        } else if (cardName == "Flood") {
            if (whiteMana >= 1 && greenMana >= 1 && colorlessManaSum - whiteMana - greenMana >= 1) {
                whiteMana--;
                greenMana--;
                getMana();
            } else {
                std::cout << "Not enough mana. " << std::endl;
            }

        } else if (cardName == "Reanimate") {
            if (blackMana >= 1) {
                blackMana--;
            } else {
                std::cout << "Not enough mana. " << std::endl;
            }

        } else if (cardName == "Plague") {
            if (blackMana >= 1 && colorlessManaSum - blackMana >= 2) {
                blackMana--;
                getMana();
                getMana();
            } else {
                std::cout << "Not enough mana. " << std::endl;
            }

        } else if (cardName == "Terror") {
            if (blackMana >= 1 && colorlessManaSum - blackMana >= 1) {
                blackMana--;
                getMana();
            } else {
                std::cout << "Not enough mana. " << std::endl;
            }

//Enchantment Cards

        } else if (cardName == "Rage") {
            if (greenMana >= 1) {
                greenMana--;
            } else {
                std::cout << "Not enough mana. " << std::endl;
            }

        } else if (cardName == "HolyWar") {
            if (whiteMana >= 1 && colorlessManaSum - whiteMana >= 1) {
                whiteMana--;
                getMana();
            } else {
                std::cout << "Not enough mana. " << std::endl;
            }

        } else if (cardName == "HolyLight") {
            if (whiteMana >= 1 && colorlessManaSum - whiteMana >= 1) {
                whiteMana--;
                getMana();
            } else {
                std::cout << "Not enough mana. " << std::endl;
            }

        } else if (cardName == "UnholyWar") {
            if (blackMana >= 1 && colorlessManaSum - blackMana >= 1) {
                blackMana--;
                getMana();
            } else {
                std::cout << "Not enough mana. " << std::endl;
            }

        } else if (cardName == "Restrain") {
            if (redMana >= 1 && colorlessManaSum - redMana >= 2) {
                redMana--;
                getMana();
                getMana();
            } else {
                std::cout << "Not enough mana. " << std::endl;
            }

        } else if (cardName == "Slow") {
            if (blackMana >= 1) {
                blackMana--;
            } else {
                std::cout << "Not enough mana. " << std::endl;
            }

        }

    }

//check if mana is enough to play card

    bool isManaEnough(std::string c) {colorlessManaSum = whiteMana + redMana + greenMana + blueMana + blackMana;
        cardName = c;

//Creature Cards

        if (cardName == "Soldier") {
            if (whiteMana > 0) {return true;

            } else {
                return false;
            }


        } else if (cardName == "ArmoredPegasus") {
            if (whiteMana >= 1 && colorlessManaSum - whiteMana >= 1) {return true;
            } else {
                return false;
            }

        } else if (cardName == "WhiteKnight") {
            if (whiteMana >= 2) {return true;
            } else {
                return false;
            }

        } else if (cardName == "AngryBear") {
            if (greenMana >= 1 && colorlessManaSum - greenMana >= 2) {return true;

            } else {
                return false;
            }

        } else if (cardName == "Guard") {
            if (whiteMana >= 2 && colorlessManaSum - whiteMana >= 2) {return true;
            } else {
                return false;
            }

        } else if (cardName == "Werewolf") {
            if (whiteMana >= 1 && greenMana >= 1 && colorlessManaSum - whiteMana - greenMana >= 2) {return true;
            } else {
                return false;
            }

        } else if (cardName == "Skeleton") {
            if (blackMana >= 1) {return true;
            } else {
                return false;
            }

        } else if (cardName == "Ghost") {
            if (blackMana >= 1 && colorlessManaSum - blackMana >= 1) {return true;
            } else {
                return false;
            }

        } else if (cardName == "BlackKnight") {
            if (blackMana >= 2) {return true;
            } else {
                return false;
            }

        } else if (cardName == "OrcManiac") {
            if (redMana >= 1 && colorlessManaSum - redMana >= 2) {return true;
            } else {
                return false;
            }

        } else if (cardName == "Hobgoblin") {
            if (redMana >= 1 && blackMana >= 1 && colorlessManaSum - redMana - blackMana >= 1) {return true;
            } else {
                return false;
            }

        } else if (cardName == "Vampire") {
            if (blackMana >= 1 && colorlessManaSum - blackMana >= 3) {return true;
            } else {
                return false;

            }

//Sorcery Cards

        } else if (cardName == "Disenchant") {
            if (whiteMana >= 1 && colorlessManaSum - whiteMana >= 1) {return true;
            } else {
                return false;
            }

        } else if (cardName == "LightningBolt") {
            if (greenMana >= 1 && colorlessManaSum - greenMana >= 1) {return true;
            } else {
                return false;
            }

        } else if (cardName == "Flood") {
            if (whiteMana >= 1 && greenMana >= 1 && colorlessManaSum - whiteMana - greenMana >= 1) {return true;
            } else {
                return false;
            }

        } else if (cardName == "Reanimate") {
            if (blackMana >= 1) {return true;
            } else {
                return false;
            }

        } else if (cardName == "Plague") {
            if (blackMana >= 1 && colorlessManaSum - blackMana >= 2) {return true;
            } else {
                return false;
            }

        } else if (cardName == "Terror") {
            if (blackMana >= 1 && colorlessManaSum - blackMana >= 1) {return true;
            } else {
                return false;
            }

//Enchantment Cards

        } else if (cardName == "Rage") {
            if (greenMana >= 1) {return true;
            } else {
                return false;
            }

        } else if (cardName == "HolyWar") {
            if (whiteMana >= 1 && colorlessManaSum - whiteMana >= 1) {return true;
            } else {
                return false;
            }

        } else if (cardName == "HolyLight") {
            if (whiteMana >= 1 && colorlessManaSum - whiteMana >= 1) {return true;
            } else {
                return false;
            }

        } else if (cardName == "UnholyWar") {
            if (blackMana >= 1 && colorlessManaSum - blackMana >= 1) {return true;
            } else {
                return false;
            }

        } else if (cardName == "Restrain") {
            if (redMana >= 1 && colorlessManaSum - redMana >= 2) {return true;
            } else {
                return false;
            }

        } else if (cardName == "Slow") {
            if (blackMana >= 1) {return true;
            } else {
                return false;
            }

        }

        else if(cardName == "Plains"){
            return true;
        }
        else if(cardName == "Island"){
            return true;
        }
        else if(cardName == "Mountain"){
            return true;
        }
        else if(cardName == "Swamp"){
            return true;
        }
        else if(cardName == "Forest"){
            return true;
        }

    }


//Mana increment func
    virtual void increaseManaWithTap(std::string c) {
        cardName = c;

        if (c == "Forest") {
            greenMana++;
        } else if (c == "Island") {
            blueMana++;
        } else if (c == "Mountain") {
            redMana++;
        } else if (c == "Plains") {
            whiteMana++;
        } else if (c == "Swamp") {
            blackMana++;
        }
    }

};
//----------------------------------------------------------------------------------------------------------------------

class card{

protected:std::string cardName,cardType,cardColor;

public:

    card(){}
    card(std::string cN,std::string tP,std::string c):cardName(cN),cardType(tP),cardColor(c){}

    virtual void printCardName(){std::cout<<cardName;}
    void printCardtype(){std::cout<<cardType;}
    void printCardColor(){std::cout<<cardColor;}

    std::string getCardName(){return cardName;}
    std::string getCardtype(){return cardType;}
    std::string getCardColor(){return cardColor;}

    virtual void BoostStats() {};
    virtual void DecreaseStats() {};
    virtual void BoostAttack() {};
    virtual void deal1Dmg(){};
    virtual void deal2Dmg(){};
    virtual void setUntapped() {};
    virtual void setTapped(std::unique_ptr<mana>&mana){};
    virtual void setFirstStrike(){};
    virtual void setTrample(){};
    virtual void removeTrample(){};
    virtual void removeFirstStrike(){};
    virtual bool getFirstStrike(){};
    virtual bool getTrample(){};
    virtual void play(std::unique_ptr<mana>&mana){std::cout << "Card play function ";mana->cost(cardName);}
    virtual bool isManaE(std::unique_ptr<mana>&mana){return mana->isManaEnough(cardName);}
    virtual void goBaseHp(){};
    virtual bool hasTappedInfo(){};

    virtual int getHp(){}
    virtual int getAttackPower(){}
    virtual void sustainDamage(int dmg){}
    virtual bool checkDead(){}

    virtual void trampleBase(){}
    virtual void firstStrikeBase(){}


    virtual void reverseHolyWar(){}
    virtual void reverseHolylight(){}
    virtual void reverseUnholyWar(){}


};

//----------------------------------------------------------------------------------------------------------------------

class landCard: public card{
protected:

    bool hasTapped;

public:

    landCard():card (), hasTapped(0){}
    landCard(std::string cN,std::string t,bool hT): card(cN,t," "), hasTapped(hT){}

    void play(std::unique_ptr<mana>&mana){std::cout << "land card play function ";mana->cost(cardName);}

    void printCardName(){std::cout<<cardName;}
    void setUntapped() {hasTapped = false;}
    void setTapped(std::unique_ptr<mana>&mana) {mana->increaseManaWithTap(cardName); hasTapped = true;}
    bool hasTappedInfo(){return hasTapped;}
    bool isManaE(){return true;}



    //   ~landCard(){std::cout<<"land card has been destructed"<<std::endl;}
};

//----------------------------------------------------------------------------------------------------------------------

class creatureCard: public card{
protected:

    std::string manaCost;
    int attackPower;
    int baseHP;
    int hp = baseHP;
    bool baseFirstStrike;
    bool baseTrample;
    bool hasTapped;
    bool firstStrike = baseFirstStrike;
    bool trample = baseTrample;
public:
    creatureCard(): card(), attackPower(0), baseHP(0), manaCost(" "), baseFirstStrike(0), baseTrample(0){

    }
    creatureCard(std::string cardName, std::string type, std::string color, int attack, int hp, std::string cost,  bool firstStrike, bool trample):
            card(cardName,type,color), attackPower(attack), baseHP(hp), manaCost(cost), baseFirstStrike(firstStrike), baseTrample(trample){

    }



    void play(std::unique_ptr<mana>&mana){mana->cost(cardName);}

    void printCardName(){std::cout<<cardName;}
    void BoostStats(){attackPower++;hp++;}
    void DecreaseStats(){attackPower--;hp--;}
    void BoostAttack(){ attackPower += 2;}

    void reverseHolyWar(){attackPower--;hp--;}
    void reverseHolylight(){attackPower++;hp++;}
    void reverseUnholyWar(){if(attackPower==0||attackPower<0){} else if(attackPower==1){attackPower--;}else{attackPower-=2;}}


    void deal1Dmg(){hp--;}
    void deal2Dmg(){hp-=2;}

    int dealAttack(){return attackPower;}


    void setUntapped(){hasTapped = false;}
    void setTapped(){hasTapped = true;}

    void setFirstStrike(){ firstStrike = true;}
    void setTrample(){ trample = true;}
    void removeTrample(){ trample = false;}
    void removeFirstStrike(){ firstStrike = false;}
    bool getFirstStrike(){return firstStrike;}
    bool getTrample(){return trample;}

    void trampleBase(){trample=baseTrample;}
    void firstStrikeBase(){firstStrike=baseFirstStrike;}


    void goBaseHp(){hp=baseHP;}

    bool hasTappedInfo(){return hasTapped;}

    bool isManaE(std::unique_ptr<mana>&mana){return mana->isManaEnough(cardName);}

    int getHp(){return hp;}
    int getAttackPower(){return attackPower;}
    void sustainDamage(int dmg){hp-=dmg;}
    bool checkDead(){if(hp<1){ return true; }else{return false; }}




};

//----------------------------------------------------------------------------------------------------------------------

class sorceryCard: public card{

protected:

    std::string effect2,manaCost2;

public:

    sorceryCard(): card(),manaCost2(" "), effect2(" "){}
    sorceryCard(std::string cN2,std::string cC2,std::string mC2 ,std::string ef2): card(cN2,"SorceryCard",cC2),manaCost2(mC2), effect2(ef2){}

    void printCardName(){std::cout<<cardName;}
    void play(std::unique_ptr<mana>&mana){mana->cost(cardName);}
    bool isManaE(std::unique_ptr<mana>&mana){return mana->isManaEnough(cardName);}


};

//----------------------------------------------------------------------------------------------------------------------

class enhancementCard: public card{


protected:

    std::string effect2,manaCost2;

public:

    enhancementCard(): card(),manaCost2(" "), effect2(" "){}
    enhancementCard(std::string cN2,std::string cC2,std::string mC2 ,std::string ef2): card(cN2,"EnhancementCard",cC2),manaCost2(mC2), effect2(ef2){}

    void printCardName(){std::cout<<cardName;}
    void play(std::unique_ptr<mana>&mana){mana->cost(cardName);}
    bool isManaE(std::unique_ptr<mana>&mana){return mana->isManaEnough(cardName);}



};

//----------------------------------------------------------------------------------------------------------------------
class player{

protected:


    int hp=15;

    std::vector<std::shared_ptr<card>> library;
    std::vector<std::shared_ptr<card>> libraryx;
    std::vector<std::shared_ptr<card>> hand;
    std::vector<std::shared_ptr<card>> inPlay;
    std::vector<std::shared_ptr<card>> discard;
public:
    player(){}
    player(std::vector<std::shared_ptr<card>>&lib,std::vector<std::shared_ptr<card>>&hnd,std::vector<std::shared_ptr<card>>&iP,std::vector<std::shared_ptr<card>>&dc):library(lib),hand(hnd),inPlay(iP),discard(dc){libaryRandomizeAndHand7Initialy(lib,hnd);}

    void deal2Dmg(){hp-=2;}

//Randomize deck
    void libaryRandomizeAndHand7Initialy(std::vector<std::shared_ptr<card>>&lib,std::vector<std::shared_ptr<card>>&hnd){

        int a[26];

        for(int i=0;i<26;i++){
            bool isUsedBefore= false;
            a[i]=(rand()%library.size());

            for(int j=0;j<i;j++){
                if(a[i]==a[j]){
                    isUsedBefore= true;
                }
            }

            if(!isUsedBefore){libraryx.emplace_back(library[a[i]]);}
            else{i--;}

        }

        lib=library=libraryx;

        for(int i=0;i<5;i++){hnd.emplace_back(lib[lib.size()-1]);lib.pop_back();}

    }

    void susDamage(int dmg){hp-=dmg;}
    int getHp(){return hp;}


};

///effects---------------------------------------------------------------------------------------------------------------


class effect{};

//Effect destroy cards and remove their effects
class destroyCardEffect: public effect{
public:

    void destroyCardEffectFunc(std::vector<std::shared_ptr<card>>&ip,std::vector<std::shared_ptr<card>>&discard,std::string s) {

        auto it = ip.begin();
        bool isThereDestroyable = false;

        if (s == "Disenchant") {


            for (it = ip.begin(); it != ip.end(); it++) {
                if ((*it)->getCardtype() == "EnhancementCard") { isThereDestroyable = true; }
            }
            if (isThereDestroyable) {
                std::cout << "please choose which Enhancement Card you want to destroy" << std::endl;

                int i = 0;

                for (it = ip.begin(); it != ip.end(); it++) {
                    if ((*it)->getCardtype() == "EnhancementCard") {
                        std::cout << i << ")" << std::endl;
                        i++;
                        (*it)->printCardName();
                    }
                }
                std::cin >> i;

                std::cout << "opponent's " << ip[i]->getCardName()
                          << " enhancement card has been destroyed and because of it is an enhancement card its effects are reversed and canceled "
                          << std::endl;

                std::string namen;
                namen = ip[i]->getCardName();

                if (namen == "Rage") { for (it = ip.begin(); it != ip.end(); it++) { (*it)->trampleBase(); }}

                else if (namen == "HolyWar") { for (it = ip.begin(); it != ip.end(); it++) { (*it)->reverseHolyWar(); }}

                else if (namen == "HolyLight") {
                    for (it = ip.begin(); it != ip.end(); it++) { (*it)->reverseHolylight(); }
                } else if (namen == "UnholyWar") {
                    for (it = ip.begin(); it != ip.end(); it++) { (*it)->reverseUnholyWar(); }
                } else if (namen == "Restrain") {
                    for (it = ip.begin(); it != ip.end(); it++) {
                        if ((*it)->getCardColor() == "Green")(*it)->trampleBase();
                    }
                } else if (namen == "Slow") { for (it = ip.begin(); it != ip.end(); it++) { (*it)->trampleBase(); }}


                discard.emplace_back(ip[i]);
                ip.erase(ip.begin() + i);
                isThereDestroyable = false;
            } else {
                std::cout
                        << "there is no destroyable enhancement card in opponents in play cards you have wasted your card"
                        << std::endl;
            }

        } else if (s == "Flood") {
            for (it = ip.begin(); it != ip.end(); it++) {
                if ((*it)->getCardtype() == "LandCard") { isThereDestroyable = true; }
            }
            if (isThereDestroyable) {

                std::cout << "please choose which Land Card you want to destroy" << std::endl;

                int i = 0;

                for (it = ip.begin(); it != ip.end(); it++) {
                    if ((*it)->getCardtype() == "LandCard") {
                        std::cout << i << ")" << std::endl;
                        i++;
                        (*it)->printCardName();
                    }
                }
                std::cin >> i;

                std::cout << "opponent's " << ip[i]->getCardName() << " land card has been destroyed" << std::endl;

                discard.emplace_back(ip[i]);
                ip.erase(ip.begin() + i);
                isThereDestroyable = false;
            } else {
                std::cout << "there is no destroyable land card in opponents in play cards you have wasted your card"
                          << std::endl;
                isThereDestroyable = false;
            }

        } else if (s == "Terror") {
            for (it = ip.begin(); it != ip.end(); it++) {
                if ((*it)->getCardtype() == "CreatureCard") { isThereDestroyable = true; }
            }
            if (isThereDestroyable) {

                std::cout << "please choose which Creature Card you want to destroy" << std::endl;

                int i = 0;

                for (it = ip.begin(); it != ip.end(); it++) {
                    if ((*it)->getCardtype() == "CreatureCard") {
                        std::cout << i << ")" << std::endl;
                        i++;
                        (*it)->printCardName();
                    }
                }
                std::cin >> i;

                std::cout << "opponent's " << ip[i]->getCardName() << " creature card has been destroyed" << std::endl;

                discard.emplace_back(ip[i]);
                ip.erase(ip.begin() + i);
                isThereDestroyable = false;
            } else {
                std::cout
                        << "there is no destroyable creature card in opponents in play cards you have wasted your card"
                        << std::endl;
            }

        } }};

//Effect card stats
class effectForColorEffect: public effect{
public:

    void effectThatColorMembers(std::vector<std::shared_ptr<card>>&ip,std::string s) {

        auto it = ip.begin();

        if (s == "HolyWar") {
            for (it = ip.begin(); it != ip.end(); it++) {
                if ((*it)->getCardColor() == "White") {
                    (*it)->BoostStats();

                }
            }
            std::cout << "all white creature cards in your side that in play gain +1/+1 " << std::endl;
        }

        else if (s == "HolyLight") {
            for (it = ip.begin(); it != ip.end(); it++) {
                if ((*it)->getCardColor() == "Black") {
                    (*it)->DecreaseStats();
                }
            }
            std::cout<<"all black creature cards in your side that in play gain -1/-1 "<<std::endl;
        }

        else if (s == "UnholyWar") {
            for (it = ip.begin(); it != ip.end(); it++) {
                if ((*it)->getCardColor() == "Black") {
                    (*it)->BoostAttack();
                }
            }
            std::cout<<"all black creature cards in your side that in play gain +2/0 "<<std::endl;
        }
    }};

//Effect for dealing damage
class dealDamageEffect: public effect{
public:

    void dealDamage(std::vector<std::shared_ptr<card>>&ip,std::string n,std::unique_ptr<player>&player){
        auto it = ip.begin();
        if(n == "Plague"){for (it = ip.begin(); it != ip.end(); it++){(*it)->deal1Dmg();}std::cout << "all opponent's creature cards dealt 1 damage " << std::endl;}

        else if(n=="LightningBolt"){

            std::cout<<"please choose given options below and type its number"<<std::endl;
            std::cout<<"1)Deal damage to player"<<std::endl;
            std::cout<<"2)Deal damage to target creature card"<<std::endl;

            int a;

            std::cin>>a;

            if(a==1){player->deal2Dmg();std::cout<<"dealt 2 damage to the opponent player"<<std::endl;}

            else if(a==2){
                for (it = ip.begin(); it != ip.end(); it++) {
                    if ((*it)->getCardtype() == "CreatureCard") {
                        (*it)->deal2Dmg();
                        std::cout << "dealt " << (*it)->getCardName() << " 2 damage " << std::endl;
                    }
                }}

            else{std::cout<<"YOU HAVE MISSED YOUR CHANCE "<<std::endl;}


        }
    }

};

//Reanimate effect
class reviveFromGraveEffect: public effect{
public:

    void revive(std::vector<std::shared_ptr<card>>&discard, std::vector<std::shared_ptr<card>>&hand) {

        auto it = discard.begin();

        int temp = 0;
        if (discard.size() <= 0) {
            std::cout << "you dont have any card in discard pile you have missed your chance" << std::endl;
        }
        else {
            std::cout << "Choose 1 creature card from your discard pile. " << std::endl;

            bool a = false;

            while (!a) {
                for (it = discard.begin(); it != discard.end(); it++) {
                    if (hand.size() < 7) {

                        std::cout << temp << ")";
                        (*it)->printCardName();
                        temp++;


                    } else {
                        std::cout << "Your hand is full. You can not play this card." << std::endl;
                    }

                }

                std::cin >> temp;
                if (discard[temp]->getCardtype() == "CreatureCard") {
                    hand.emplace_back(discard[temp]);
                    discard.erase(discard.begin() + temp);
                    std::cout << (*it)->getCardName() << " card has moved to your hand." << std::endl;
                    a = true;
                } else {
                    std::cout << "Chosen card is not a creature card. Please choose one creature card." << std::endl;
                }
            }
        }
    }
};

//Effect cards abilities
class abilityEffect:public effect{
public:

    void effectAbility(std::vector<std::shared_ptr<card>>&ip, std::string n){
        auto it = ip.begin();
        int tmp =0;

        if(n == "Restrain"){
            for(it = ip.begin(); it != ip.end(); it++){
                if((*it)->getCardColor() == "Green"){
                    (*it)->removeTrample();
                    std::cout << (*it)->getCardName() << "'s trample ability removed " << std::endl;

                }
            }
        }


        else if(n == "Rage"){
            std::cout << "Choose one target creature card. It will gain Trample effect" << std::endl;
            bool a = false;
            while (!a) {
                for (it = ip.begin(); it != ip.end(); it++) {
                    if((*it)->getCardtype() == "CreatureCard"){
                        std::cout << tmp << ")";
                        (*it)->printCardName();
                        tmp++;
                        std::cin >> tmp;

                        if((*it)->getCardtype() == "CreatureCard"){
                            (*it)->setTrample();
                            std::cout << (*it)->getCardName() << " gain trample ability " << std::endl;
                            a=true;
                        }
                        else{
                            std::cout << "Chosen card is not a creature card. Please choose one creature card." << std::endl;
                        }
                    }
                    else{
                        std::cout << "There is no available creature card " << std::endl;
                    }
                }
            }
        }


        else if(n == "Slow") {
            std::cout << "Choose one target creature card." << std::endl;
            bool a = false;
            while (!a) {
                for (it = ip.begin(); it != ip.end(); it++) {
                    if((*it)->getCardtype() == "CreatureCard"){
                        std::cout << tmp << ")";
                        (*it)->printCardName();
                        tmp++;
                        std::cin >> tmp;

                        if((*it)->getCardtype() == "CreatureCard"){
                            (*it)->removeFirstStrike();
                            std::cout << (*it)->getCardName() << "'s first strike ability removed " << std::endl;
                            a=true;
                        }
                        else{
                            std::cout << "Chosen card is not a creature card. Please choose one creature card." << std::endl;
                        }
                    }
                    else{
                        std::cout << "There is no available creature card " << std::endl;
                    }
                }
            }

        }

    }
};

///funcs-----------------------------------------------------------------------------------------------------------------


//Print end of game information
void printLoser(std::unique_ptr<player>&player1,std::unique_ptr<player>&player2,int m) {
    std::string loser, winner;

    if (player1->getHp() < 0 || m==1) {
        loser = "player1";
        winner = "player2";
        std::cout << loser << " defeated" << std::endl;
        std::cout << winner << " survived with " << player2->getHp() << " hp and he/she is the winner" << std::endl;
    } else if (player2->getHp() < 0 || m==2) {
        loser = "player2";
        winner = "player1";
        std::cout << loser << " defeated" << std::endl;
        std::cout << winner << " survived with " << player1->getHp() << " hp and he/she is the winner" << std::endl;
    }


}


//Untap cards function
void untapped(std::vector<std::shared_ptr<card>>&ip,std::vector<std::shared_ptr<card>>&l,std::vector<std::shared_ptr<card>>&d,std::vector<std::shared_ptr<card>>&h){
    auto it = ip.begin();

    for (it = ip.begin(); it != ip.end(); it++){
        (*it)->setUntapped();
    }
    for (it = l.begin(); it != l.end(); it++){
        (*it)->setUntapped();
    }
    for (it = d.begin(); it != d.end(); it++){
        (*it)->setUntapped();
    }
    for (it = h.begin(); it != h.end(); it++){
        (*it)->setUntapped();
    }
}


//Return creature card's hp to their baseHP
void baseHp(std::vector<std::shared_ptr<card>>&ip,std::vector<std::shared_ptr<card>>&l,std::vector<std::shared_ptr<card>>&d,std::vector<std::shared_ptr<card>>&h){
    auto it = ip.begin();

    for (it = ip.begin(); it != ip.end(); it++){
        (*it)->goBaseHp();
    }
    for (it = l.begin(); it != l.end(); it++){
        (*it)->goBaseHp();
    }
    for (it = d.begin(); it != d.end(); it++){
        (*it)->goBaseHp();
    }
    for (it = h.begin(); it != h.end(); it++){
        (*it)->goBaseHp();
    }
}

//void combat(std::unique_ptr<card>&attacker,std::unique_ptr<card>&defender,std::unique_ptr<player>&playerOp){
//
//    int excessAttackPower;
//
//    if(defender->getCardtype()=="CreatureCard"){
//        if(attacker->getFirstStrike()){
//            attacker->sustainDamage(defender->getAttackPower());
//            if(attacker->getAttackPower()<defender->getHp()){
//                defender->sustainDamage(attacker->getAttackPower());
//            }
//
//        }
//        else if(attacker->getTrample()){
//            defender->sustainDamage(attacker->getAttackPower());
//            attacker->sustainDamage(defender->getAttackPower());
//            if(attacker->getAttackPower()>defender->getHp()){
//                excessAttackPower = attacker->getAttackPower()-defender->getHp();
//                playerOp->susDamage(excessAttackPower);
//            }
//            else if(attacker->getFirstStrike() && attacker->getTrample()){
//                attacker->sustainDamage(defender->getAttackPower());
//                if(attacker->getAttackPower()<defender->getHp()){
//                    defender->sustainDamage(attacker->getAttackPower());
//                    if(attacker->getAttackPower()>defender->getHp()){
//                        excessAttackPower = attacker->getAttackPower()-defender->getHp();
//                        playerOp->susDamage(excessAttackPower);
//                    }
//                }   }
//            else{
//                defender->sustainDamage(attacker->getAttackPower());
//                attacker->sustainDamage(defender->getAttackPower());
//            }
//        }
//        else{playerOp->susDamage(attacker->getAttackPower());}
//
//    }
//    else{playerOp->susDamage(attacker->getAttackPower());}
//}


//Attack function of creature cards
void combat (std::vector<std::shared_ptr<card>>&attackerInplay,int i,std::vector<std::shared_ptr<card>>&defenderInplay,int o,std::unique_ptr<player>&playerOp,std::vector<std::shared_ptr<card>>&dc1,std::vector<std::shared_ptr<card>>&dc2){

    int excessAttackPower;


    if(defenderInplay[o]->getCardtype()=="CreatureCard"){

        if(attackerInplay[i]->getFirstStrike()){
            defenderInplay[o]->sustainDamage(attackerInplay[i]->getAttackPower());
            std::cout << attackerInplay[i]->getCardName() << " hit " << attackerInplay[i]->getAttackPower() << " damage to " << defenderInplay[o]->getCardName() << std::endl;

            if(defenderInplay[o]->checkDead()){std::cout << defenderInplay[o]->getCardName() << " is destroyed " << std::endl;dc2.emplace_back(defenderInplay[o]);defenderInplay.erase(defenderInplay.begin()+o);}

            if(attackerInplay[i]->getAttackPower()<defenderInplay[o]->getHp()){
                attackerInplay[i]->sustainDamage(defenderInplay[o]->getAttackPower());
                std::cout << defenderInplay[o]->getCardName() << " hit " << defenderInplay[o]->getAttackPower() << " damage to " << attackerInplay[o]->getCardName() << std::endl;

                if(attackerInplay[i]->checkDead()){std::cout << attackerInplay[i]->getCardName() << " is destroyed " << std::endl;dc1.emplace_back(attackerInplay[i]);attackerInplay.erase(attackerInplay.begin()+i);}
            }

        }




        else if(defenderInplay[o]->getFirstStrike()){
            attackerInplay[i]->sustainDamage(defenderInplay[o]->getAttackPower());
            std::cout << defenderInplay[o]->getCardName() << " hit " << defenderInplay[o]->getAttackPower() << " damage to " << attackerInplay[o]->getCardName() << std::endl;

            if(attackerInplay[i]->checkDead()){std::cout << attackerInplay[i]->getCardName() << " is destroyed " << std::endl;dc1.emplace_back(attackerInplay[i]);attackerInplay.erase(attackerInplay.begin()+i);}
            if(defenderInplay[o]->getAttackPower()<attackerInplay[i]->getHp()){
                defenderInplay[o]->sustainDamage(attackerInplay[i]->getAttackPower());
                std::cout << attackerInplay[i]->getCardName() << " hit " << attackerInplay[i]->getAttackPower() << " damage to " << defenderInplay[o]->getCardName() << std::endl;

                if(defenderInplay[o]->checkDead()){std::cout << defenderInplay[o]->getCardName() << " is destroyed " << std::endl;dc2.emplace_back(defenderInplay[o]);defenderInplay.erase(defenderInplay.begin()+o);}
            }
        }





        else if(attackerInplay[i]->getFirstStrike() && defenderInplay[o]->getFirstStrike()){
            defenderInplay[o]->sustainDamage(attackerInplay[i]->getAttackPower());
            std::cout << attackerInplay[i]->getCardName() << " hit " << attackerInplay[i]->getAttackPower() << " damage to " << defenderInplay[o]->getCardName() << std::endl;

            attackerInplay[i]->sustainDamage(defenderInplay[o]->getAttackPower());
            std::cout << defenderInplay[o]->getCardName() << " hit " << defenderInplay[o]->getAttackPower() << " damage to " << attackerInplay[o]->getCardName() << std::endl;

            if(defenderInplay[o]->checkDead()){std::cout << defenderInplay[o]->getCardName() << " is destroyed " << std::endl;dc2.emplace_back(defenderInplay[o]);defenderInplay.erase(defenderInplay.begin()+o);}
            if(attackerInplay[i]->checkDead()){std::cout << attackerInplay[i]->getCardName() << " is destroyed " << std::endl;dc1.emplace_back(attackerInplay[i]);attackerInplay.erase(attackerInplay.begin()+i);}
        }




        else if(attackerInplay[i]->getTrample()) {
            defenderInplay[o]->sustainDamage(defenderInplay[o]->getAttackPower());
            std::cout << attackerInplay[i]->getCardName() << " hit " << attackerInplay[i]->getAttackPower() << " damage to " << defenderInplay[o]->getCardName() << std::endl;

            attackerInplay[i]->sustainDamage(defenderInplay[o]->getAttackPower());
            std::cout << defenderInplay[o]->getCardName() << " hit " << defenderInplay[o]->getAttackPower() << " damage to " << attackerInplay[o]->getCardName() << std::endl;

            if (attackerInplay[i]->getAttackPower() > defenderInplay[o]->getHp()) {
                excessAttackPower = attackerInplay[i]->getAttackPower() - defenderInplay[o]->getHp();
                playerOp->susDamage(excessAttackPower);
                std::cout << "Because of attacker card's trample ability " << excessAttackPower << " dealt to opponent player " << std::endl;
            }
        }




        else if(defenderInplay[o]->getTrample()){
            defenderInplay[o]->sustainDamage(attackerInplay[i]->getAttackPower());
            std::cout << attackerInplay[i]->getCardName() << " hit " << attackerInplay[i]->getAttackPower() << " damage to " << defenderInplay[o]->getCardName() << std::endl;

            attackerInplay[i]->sustainDamage(defenderInplay[o]->getAttackPower());
            std::cout << defenderInplay[o]->getCardName() << " hit " << defenderInplay[o]->getAttackPower() << " damage to " << attackerInplay[o]->getCardName() << std::endl;

            if(defenderInplay[o]->checkDead()){std::cout << defenderInplay[o]->getCardName() << " is destroyed " << std::endl;dc2.emplace_back(defenderInplay[o]);defenderInplay.erase(defenderInplay.begin()+o);}
            if(attackerInplay[i]->checkDead()){std::cout << attackerInplay[i]->getCardName() << " is destroyed " << std::endl;dc1.emplace_back(attackerInplay[i]);attackerInplay.erase(attackerInplay.begin()+i);}
        }




        else if(attackerInplay[i]->getFirstStrike() && attackerInplay[i]->getTrample()){
            defenderInplay[o]->sustainDamage(attackerInplay[i]->getAttackPower());
            std::cout << attackerInplay[i]->getCardName() << " hit " << attackerInplay[i]->getAttackPower() << " damage to " << defenderInplay[o]->getCardName() << std::endl;

            if(defenderInplay[o]->checkDead()){std::cout << defenderInplay[o]->getCardName() << " is destroyed " << std::endl;dc2.emplace_back(defenderInplay[o]);defenderInplay.erase(defenderInplay.begin()+o);}

            if(attackerInplay[i]->getAttackPower()<defenderInplay[o]->getHp()){
                attackerInplay[i]->sustainDamage(defenderInplay[o]->getAttackPower());
                std::cout << defenderInplay[o]->getCardName() << " hit " << defenderInplay[o]->getAttackPower() << " damage to " << attackerInplay[o]->getCardName() << std::endl;

                if(attackerInplay[i]->getAttackPower()>defenderInplay[o]->getHp()){
                    excessAttackPower = attackerInplay[i]->getAttackPower()-defenderInplay[o]->getHp();
                    playerOp->susDamage(excessAttackPower);
                    std::cout << "Because of attacker card's trample ability " << excessAttackPower << " dealt to opponent player " << std::endl;
                }
            }

        }




        else{
            defenderInplay[o]->sustainDamage(attackerInplay[i]->getAttackPower());
            std::cout << attackerInplay[i]->getCardName() << " hit " << attackerInplay[i]->getAttackPower() << " damage to " << defenderInplay[o]->getCardName() << std::endl;

            attackerInplay[i]->sustainDamage(defenderInplay[o]->getAttackPower());
            std::cout << defenderInplay[o]->getCardName() << " hit " << defenderInplay[o]->getAttackPower() << " damage to " << attackerInplay[o]->getCardName() << std::endl;

            if(defenderInplay[o]->checkDead()){std::cout << defenderInplay[o]->getCardName() << " is destroyed " << std::endl;dc2.emplace_back(defenderInplay[o]);defenderInplay.erase(defenderInplay.begin()+o);}
            if(attackerInplay[i]->checkDead()){std::cout << attackerInplay[i]->getCardName() << " is destroyed " << std::endl;dc1.emplace_back(attackerInplay[i]);attackerInplay.erase(attackerInplay.begin()+i);}
        }


    }
    else{std::cout << "Player take " << attackerInplay[i]->getAttackPower() << " damage" << std::endl; playerOp->susDamage(attackerInplay[i]->getAttackPower()); }

}


//For print the cards in inPlay
void printInPlay(std::vector<std::shared_ptr<card>>&ip){
    auto it = ip.begin();
    int counter = 0;
    std::cout << " cards that in play: " << std::endl;
    for(it = ip.begin(); it != ip.end(); it++){
        std::cout << counter << ")" << (*it)->getCardName() << "  ";
        counter++;
    }
}

//For print the cards in hand
void printHand(std::vector<std::shared_ptr<card>>&hand){
    auto it = hand.begin();
    int counter = 0;
    std::cout << " cards that in hand: " << std::endl;
    for(it = hand.begin(); it != hand.end(); it++){
        std::cout << counter << ")" << (*it)->getCardName() << "  ";
        counter++;
    }
}


///----------------------------------------------------------------------------------------------------------------------

int main() {
    srand(time(NULL));
    system("Color C");
    system("TREE");

    /// to form libraries

    std::vector<std::shared_ptr<card>> library1;
    std::vector<std::shared_ptr<card>> library2;

    /// to form hands

    std::vector<std::shared_ptr<card>> hand1;
    std::vector<std::shared_ptr<card>> hand2;

    /// to form inPlay

    std::vector<std::shared_ptr<card>> inPlay1;
    std::vector<std::shared_ptr<card>> inPlay2;

    /// to form discards

    std::vector<std::shared_ptr<card>> discard1;
    std::vector<std::shared_ptr<card>> discard2;

    /// to form manas
    std::unique_ptr<mana> mana1 = std::make_unique<mana>();
    std::unique_ptr<mana> mana2 = std::make_unique<mana>();

    /// to form effectObjects
    destroyCardEffect destroyCardEffectObj;
    effectForColorEffect effectForColorEffectObj;
    dealDamageEffect dealDamageEffectObj;
    reviveFromGraveEffect reviveFromGraveEffectObj;
    abilityEffect abilityEffectObj;



///Cards-----------------------------------------------------------------------------------------------------------------

    /// land cards

    std::shared_ptr<landCard> forest1 = std::make_shared<landCard>("Forest", "LandCard", 0);
    std::shared_ptr<landCard> forest2 = std::make_shared<landCard>("Forest", "LandCard", 0);
    std::shared_ptr<landCard> forest3 = std::make_shared<landCard>("Forest", "LandCard", 0);

    std::shared_ptr<landCard> island = std::make_shared<landCard>("Island", "LandCard", 0);

    std::shared_ptr<landCard> mountain1 = std::make_shared<landCard>("Mountain", "LandCard", 0);
    std::shared_ptr<landCard> mountain2 = std::make_shared<landCard>("Mountain", "LandCard", 0);
    std::shared_ptr<landCard> mountain3 = std::make_shared<landCard>("Mountain", "LandCard", 0);

    std::shared_ptr<landCard> plains1 = std::make_shared<landCard>("Plains", "LandCard", 0);
    std::shared_ptr<landCard> plains2 = std::make_shared<landCard>("Plains", "LandCard", 0);
    std::shared_ptr<landCard> plains3 = std::make_shared<landCard>("Plains", "LandCard", 0);
    std::shared_ptr<landCard> plains4 = std::make_shared<landCard>("Plains", "LandCard", 0);
    std::shared_ptr<landCard> plains5 = std::make_shared<landCard>("Plains", "LandCard", 0);

    std::shared_ptr<landCard> swamp1 = std::make_shared<landCard>("Swamp", "LandCard", 0);
    std::shared_ptr<landCard> swamp2 = std::make_shared<landCard>("Swamp", "LandCard", 0);
    std::shared_ptr<landCard> swamp3 = std::make_shared<landCard>("Swamp", "LandCard", 0);
    std::shared_ptr<landCard> swamp4 = std::make_shared<landCard>("Swamp", "LandCard", 0);
    std::shared_ptr<landCard> swamp5 = std::make_shared<landCard>("Swamp", "LandCard", 0);

    /// creature cards

    std::shared_ptr<creatureCard> soldier1 = std::make_shared<creatureCard>("Soldier", "CreatureCard", "White", 1, 1,
                                                                            "W", false, false);
    std::shared_ptr<creatureCard> soldier2 = std::make_shared<creatureCard>("Soldier", "CreatureCard", "White", 1, 1,
                                                                            "W", false, false);
    std::shared_ptr<creatureCard> soldier3 = std::make_shared<creatureCard>("Soldier", "CreatureCard", "White", 1, 1,
                                                                            "W", false, false);

    std::shared_ptr<creatureCard> armoredPegasus1 = std::make_shared<creatureCard>("ArmoredPegasus", "CreatureCard",
                                                                                   "White", 1, 2, "1W", false, false);
    std::shared_ptr<creatureCard> armoredPegasus2 = std::make_shared<creatureCard>("ArmoredPegasus", "CreatureCard",
                                                                                   "White", 1, 2, "1W", false, false);

    std::shared_ptr<creatureCard> whiteKnight1 = std::make_shared<creatureCard>("WhiteKnight", "CreatureCard", "White",
                                                                                2, 2, "WW", true, false);
    std::shared_ptr<creatureCard> whiteKnight2 = std::make_shared<creatureCard>("WhiteKnight", "CreatureCard", "White",
                                                                                2, 2, "WW", true, false);

    std::shared_ptr<creatureCard> angryBear = std::make_shared<creatureCard>("AngryBear", "CreatureCard", "Green", 3, 2,
                                                                             "2G", false, true);

    std::shared_ptr<creatureCard> guard = std::make_shared<creatureCard>("Guard", "CreatureCard", "White", 2, 5, "2WW",
                                                                         false, false);

    std::shared_ptr<creatureCard> werewolf = std::make_shared<creatureCard>("Werewolf", "CreatureCard", "Green", 4, 6,
                                                                            "2GW", false, true);

    std::shared_ptr<creatureCard> skeleton1 = std::make_shared<creatureCard>("Skeleton", "CreatureCard", "Black", 1, 1,
                                                                             "B", false, false);
    std::shared_ptr<creatureCard> skeleton2 = std::make_shared<creatureCard>("Skeleton", "CreatureCard", "Black", 1, 1,
                                                                             "B", false, false);
    std::shared_ptr<creatureCard> skeleton3 = std::make_shared<creatureCard>("Skeleton", "CreatureCard", "Black", 1, 1,
                                                                             "B", false, false);

    std::shared_ptr<creatureCard> ghost1 = std::make_shared<creatureCard>("Ghost", "CreatureCard", "Black", 2, 1, "1B",
                                                                          false, false);
    std::shared_ptr<creatureCard> ghost2 = std::make_shared<creatureCard>("Ghost", "CreatureCard", "Black", 2, 1, "1B",
                                                                          false, false);

    std::shared_ptr<creatureCard> blackKnight1 = std::make_shared<creatureCard>("BlackKnight", "CreatureCard", "Black",
                                                                                2, 2, "BB", true, false);
    std::shared_ptr<creatureCard> blackKnight2 = std::make_shared<creatureCard>("BlackKnight", "CreatureCard", "Black",
                                                                                2, 2, "BB", true, false);

    std::shared_ptr<creatureCard> orcManiac = std::make_shared<creatureCard>("OrcManiac", "CreatureCard", "Red", 4, 1,
                                                                             "2R", false, false);

    std::shared_ptr<creatureCard> hobgoblin = std::make_shared<creatureCard>("Hobgoblin", "CreatureCard", "Red", 3, 3,
                                                                             "1RB", false, false);

    std::shared_ptr<creatureCard> vampire = std::make_shared<creatureCard>("Vampire", "CreatureCard", "Black", 6, 3,
                                                                           "3B", false, false);

    // sorcery cards

    std::shared_ptr<sorceryCard> disenchant = std::make_shared<sorceryCard>("Disenchant", "White", "1W",
                                                                            "Destroy 1 Target Enchantment");

    std::shared_ptr<sorceryCard> lightningBolt = std::make_shared<sorceryCard>("LightningBolt", "Green", "1G",
                                                                               "Deal 2 dmg to target creature or player");

    std::shared_ptr<sorceryCard> flood1 = std::make_shared<sorceryCard>("Flood", "Green", "1GW",
                                                                        "Destroy 1 Target Land");
    std::shared_ptr<sorceryCard> flood2 = std::make_shared<sorceryCard>("Flood", "Green", "1GW",
                                                                        "Destroy 1 Target Land");

    std::shared_ptr<sorceryCard> reanimate = std::make_shared<sorceryCard>("Reanimate", "Black", "B",
                                                                           "Return 1 character card from discard to hand");

    std::shared_ptr<sorceryCard> plague = std::make_shared<sorceryCard>("Plague", "Black", "2B",
                                                                        "Deal 1 dmg to all creatures");

    std::shared_ptr<sorceryCard> terror1 = std::make_shared<sorceryCard>("Terror", "Black", "1B",
                                                                         "Destroy 1 Target Creature");
    std::shared_ptr<sorceryCard> terror2 = std::make_shared<sorceryCard>("Terror", "Black", "1B",
                                                                         "Destroy 1 Target Creature");

    // enchantment cards

    std::shared_ptr<enhancementCard> rage = std::make_shared<enhancementCard>("Rage", "Green", "G",
                                                                              "1 Target creature gains Trample");

    std::shared_ptr<enhancementCard> holyWar = std::make_shared<enhancementCard>("HolyWar", "White", "1W",
                                                                                 "All white creatures gain +1/+1");

    std::shared_ptr<enhancementCard> holyLight = std::make_shared<enhancementCard>("HolyLight", "White", "1W",
                                                                                   "All black creatures gain -1/-1");

    std::shared_ptr<enhancementCard> unholyWar = std::make_shared<enhancementCard>("UnholyWar", "Black", "1B",
                                                                                   "All black creatures gain +2/+0");

    std::shared_ptr<enhancementCard> restrain = std::make_shared<enhancementCard>("Restrain", "Red", "2R",
                                                                                  "All green creatures lose Trample");

    std::shared_ptr<enhancementCard> slow = std::make_shared<enhancementCard>("Slow", "Black", "B",
                                                                              "1 Target creature loses First Strike");


//----------------------------------------------------------------------------------------------------------------------

///lib1

    library1.emplace_back(plains1);
    library1.emplace_back(plains2);
    library1.emplace_back(plains3);
    library1.emplace_back(plains4);
    library1.emplace_back(plains5);

    library1.emplace_back(forest1);
    library1.emplace_back(forest2);
    library1.emplace_back(forest3);

    library1.emplace_back(island);

    library1.emplace_back(soldier1);
    library1.emplace_back(soldier2);
    library1.emplace_back(soldier3);

    library1.emplace_back(armoredPegasus1);
    library1.emplace_back(armoredPegasus2);

    library1.emplace_back(whiteKnight1);
    library1.emplace_back(whiteKnight2);

    library1.emplace_back(angryBear);

    library1.emplace_back(guard);

    library1.emplace_back(werewolf);

    library1.emplace_back(disenchant);
    library1.emplace_back(lightningBolt);
    library1.emplace_back(flood1);
    library1.emplace_back(flood2);

    library1.emplace_back(rage);
    library1.emplace_back(holyWar);
    library1.emplace_back(holyLight);

///lib2

    library2.emplace_back(swamp1);
    library2.emplace_back(swamp2);
    library2.emplace_back(swamp3);
    library2.emplace_back(swamp4);
    library2.emplace_back(swamp5);

    library2.emplace_back(mountain1);
    library2.emplace_back(mountain2);
    library2.emplace_back(mountain3);

    library2.emplace_back(island);

    library2.emplace_back(skeleton1);
    library2.emplace_back(skeleton2);
    library2.emplace_back(skeleton3);

    library2.emplace_back(ghost1);
    library2.emplace_back(ghost2);

    library2.emplace_back(blackKnight1);
    library2.emplace_back(blackKnight2);

    library2.emplace_back(orcManiac);

    library2.emplace_back(hobgoblin);

    library2.emplace_back(vampire);

    library2.emplace_back(reanimate);
    library2.emplace_back(plague);
    library2.emplace_back(terror1);
    library2.emplace_back(terror2);

    library2.emplace_back(unholyWar);
    library2.emplace_back(restrain);
    library2.emplace_back(slow);

//----------------------------------------------------------------------------------------------------------------------

    /// to form players
    std::unique_ptr<player> player1 = std::make_unique<player>(library1, hand1, inPlay1, discard1);
    std::unique_ptr<player> player2 = std::make_unique<player>(library2, hand2, inPlay2, discard2);

//Action----------------------------------------------------------------------------------------------------------------

//    std::vector<std::shared_ptr<card>> cardx ;
//
//    cardx.emplace_back(soldier1);                             //  YES!!!!
//
//    auto it=cardx.begin();
//    (*it)->play(mana1);
//-------------------------------------
//    std::vector<card> cardx ;
//
//    cardx.emplace_back(*soldier1);                            // YES BUT PLAYS CARD NO VIRTUAL FUNC
//
//    auto it=cardx.begin();
//    it->play(mana1);
//-------------------------------------
//    std::vector<std::shared_ptr<card>> cardx ;
//
//    cardx.emplace_back(soldier1);                                 //  YES!!!!
//
//    cardx[0]->play(mana1);
//-------------------------------------
//    std::shared_ptr<std::vector<card>> cardx ;
//
//    cardx->emplace_back(*soldier1);                                 //  NO!!!!
//
//    auto it=cardx->begin();
//    it->play(mana1);


    std::cout << "*** For a better gaming experience use the table that shows the game cards and their features. 233*** OO1" << std::endl << std::endl;

    int turnCounter = 1;

    while (true) {



        /////////////////////////////////ACTİON FOR PLAYER1///////////////////////////////////////////

        if (player1->getHp() > 0 && player2->getHp() > 0) {


            baseHp(inPlay1, library1, discard1, hand1);
            //Print players hp at each start of turn
            std::cout << "Player1's hp: " << player1->getHp() << "  Player2's hp: " << player2->getHp() << std::endl << std::endl;

            //Print cards that in play for player1
            std::cout << "Player1's: "; printInPlay(inPlay1); std::cout << std::endl;

            //Print cards that in play for player2
            std::cout << "Player2's: "; printInPlay(inPlay2); std::cout << std::endl;



            //draw phase for player1
            std::cout << std::endl;
            std::cout << "----------------------------------DRAW PHASE----------------------------------" << std::endl
                      << std::endl;


            if (library1.size() != 0 && hand1.size()<7) {
                std::cout << "Player1 draw: " << library1[library1.size() - 1]->getCardName() << std::endl;
                hand1.emplace_back(library1[library1.size() - 1]);
                library1.pop_back();
            } else if (hand1.size() >=7  && library1.size() != 0) {
                std::cout
                        << "you have 7 cards in your hand its the limit you can not draw 1 more. Drawn card send to discard pile."
                        << std::endl << std::endl;
                discard1.emplace_back(library1[library1.size() - 1]);
                library1.pop_back();
            } else {
                printLoser(player1, player2, 1);
                break;
            }

            baseHp(inPlay1, library1, discard1, hand1);
            if (player1->getHp() <= 0 || player2->getHp() <= 0) {printLoser(player1, player2, 3); break;}
            //untap phase for player1

            std::cout << std::endl;
            std::cout << "----------------------------------UNTAP PHASE FOR PLAYER 1 ----------------------------------"
                      << std::endl << std::endl;
            std::cout << "All tapped cards in play become once again untapped" << std::endl;

            untapped(inPlay1, library1, discard1, hand1);

            baseHp(inPlay1, library1, discard1, hand1);
            if (player1->getHp() <= 0 || player2->getHp() <= 0) {printLoser(player1, player2, 3); break;}
            //play phase for player1
            std::cout << std::endl;
            std::cout << "----------------------------------PLAY PHASE FOR PLAYER 1 ----------------------------------"
                      << std::endl << std::endl;

            for(int i=0;i<inPlay1.size();i++){if(inPlay1[i]->getCardtype()=="LandCard"){inPlay1[i]->setTapped(mana1);}}
            std::cout
                    << "now you can play your cards as possible your mana allows you but you can only play 1 land card"
                    << std::endl;

            std::cout << std::endl;

            int a = 0;

            while (true) {

                mana1->printMana();
                std::cout << "choose the cards below from your hand and type number of it to play it" << std::endl;

                std::cout << std::endl;

                auto it444=hand1.begin();
                int i = 0;

                for (it444 = hand1.begin(); it444 != hand1.end(); it444++) {
                    std::cout << i << ")";
                    (*it444)->printCardName();
                    std::cout << "  ";
                    i++;
                }

                std::cout << std::endl;

                std::cout << "type 9 to pass play phase " << std::endl;
                std::cin >> i;

                std::cout << std::endl;
                if (player1->getHp() <= 0 || player2->getHp() <= 0) {printLoser(player1, player2, 3); break;}

                if(i==9){break;}

                else if (hand1[i]->isManaE(mana1)) {

                    std::vector<card>::iterator itXXX;

                    if (hand1[i]->getCardtype() == "LandCard") {
                        if (a < 1) {
                            a++;
                            std::cout << "Player1 played: " << hand1[i]->getCardName() << std::endl;hand1[i]->setTapped(mana1);
                            hand1[i]->play(mana1);
                            //(itXXX+i)->play(mana1);
                            inPlay1.emplace_back(hand1[i]);
                            hand1.erase(hand1.begin() + i);

                        } else {
                            std::cout << "you already have played land card you can not play 1 more" << std::endl;
                        }

                    } else if (hand1[i]->getCardtype() == "SorceryCard") {
                        std::cout << "Player1 played: " << hand1[i]->getCardName() << std::endl;
                        hand1[i]->play(mana1);

                        if (hand1[i]->getCardName() == "Disenchant") {
                            destroyCardEffectObj.destroyCardEffectFunc(inPlay2, discard2, hand1[i]->getCardName());
                        } else if (hand1[i]->getCardName() == "LightningBolt") {
                            dealDamageEffectObj.dealDamage(inPlay2, hand1[i]->getCardName(), player2);
                        } else if (hand1[i]->getCardName() == "Flood") {
                            destroyCardEffectObj.destroyCardEffectFunc(inPlay2, discard2, hand1[i]->getCardName());
                        } else if (hand1[i]->getCardName() == "Reanimate") {
                            reviveFromGraveEffectObj.revive(discard1, hand1);
                        } else if (hand1[i]->getCardName() == "Plague") {
                            dealDamageEffectObj.dealDamage(inPlay2, hand1[i]->getCardName(), player2);
                        } else if (hand1[i]->getCardName() == "Terror") {
                            destroyCardEffectObj.destroyCardEffectFunc(inPlay2, discard2, hand1[i]->getCardName());
                        }

                        inPlay1.emplace_back(hand1[i]);
                        hand1.erase(hand1.begin() + i);


                    } else if (hand1[i]->getCardtype() == "EnhancementCard") {
                        std::cout << "Player1 played: " << hand1[i]->getCardName() << std::endl;
                        hand1[i]->play(mana1);

                        if (hand1[i]->getCardName() == "Rage") {
                            abilityEffectObj.effectAbility(inPlay1, hand1[i]->getCardName());
                        } else if (hand1[i]->getCardName() == "HolyWar") {
                            effectForColorEffectObj.effectThatColorMembers(inPlay1, hand1[i]->getCardName());
                        } else if (hand1[i]->getCardName() == "HolyLight") {
                            effectForColorEffectObj.effectThatColorMembers(inPlay2, hand1[i]->getCardName());
                        } else if (hand1[i]->getCardName() == "UnholyWar") {
                            effectForColorEffectObj.effectThatColorMembers(inPlay1, hand1[i]->getCardName());
                        } else if (hand1[i]->getCardName() == "Restrain") {
                            abilityEffectObj.effectAbility(inPlay2, hand1[i]->getCardName());
                        } else if (hand1[i]->getCardName() == "Slow") {
                            abilityEffectObj.effectAbility(inPlay2, hand1[i]->getCardName());
                        }

                        inPlay1.emplace_back(hand1[i]);
                        hand1.erase(hand1.begin() + i);


                    } else {
                        std::cout << "Player1 played: " << hand1[i]->getCardName() << std::endl;
                        hand1[i]->play(mana1);
                        inPlay1.emplace_back(hand1[i]);
                        hand1.erase(hand1.begin() + i);
                    }
                    if (player1->getHp() <= 0 || player2->getHp() <= 0) {printLoser(player1, player2, 3); break;}
                } else { std::cout << "you dont have enough mana to play this Card" << std::endl; }

/*
                std::cout
                        << "You can tap your land cards if you want please choose and type a number which are given below. if there is no Land card then only option will be 9 please type 9 in this case"
                        << std::endl;
                std::cout << std::endl;

                int l = 0;

                for (int it333 = 0; it333 < inPlay1.size(); it333++) {
                    if (inPlay1[it333]->getCardtype() == "LandCard" && !inPlay1[it333]->hasTappedInfo()) {
                        std::cout << it333 << ")" << inPlay1[it333]->getCardName() << std::endl;
                        l++;
                    }
                    std::cout << "9) I'm done with tapping land cards" << std::endl;

                    int ll;
                    std::cin >> ll;
                    if (ll != 9) { for (int iii = 0; iii < l; iii++) { inPlay1[ll]->setTapped(mana1); }}
                    else if(ll=9){break;}



                }
                */
                std::cout << "to end this phase please type 9 to continue type 0 " << std::endl;
                int s;
                std::cin >> s;
                if (s == 9) { break; }
            }
            if (player1->getHp() <= 0 || player2->getHp() <= 0) {printLoser(player1, player2, 3); break;}
            baseHp(inPlay1, library1, discard1, hand1);

            //combat phase for player1
            std::cout << std::endl;
            std::cout
                    << "----------------------------------COMBAT PHASE FOR PLAYER 1 ----------------------------------"
                    << std::endl << std::endl;

            int ops;

            int counter=0;
            for (int i = 0; i < inPlay1.size(); i++) {
                if (inPlay1[i]->getCardtype() == "CreatureCard") { counter++; }
            }

            if (counter > 0) {

                std::cout
                        << "please choose your attack squad one by one via typing its index number.Untapped creature cards will be listed below"
                        << std::endl << std::endl;

                for (int i = 0; i < inPlay1.size(); i++) {
                    if (!inPlay1[i]->hasTappedInfo() && inPlay1[i]->getCardtype() == "CreatureCard") {
                        std::cout << i << ")" << inPlay1[i]->getCardName() << "  ";
                    }
                }

                bool done = false;
                int indexNumber;
                int squadIndexLog[9];
                int mmm = 0;

                std::cout << std::endl;
                std::cout
                        << "if you just want to pass and if you dont want to attack please type 9; if you type any number expect 9 you have to attack"
                        << std::endl;
                int ops2;
                while (!done) {


                    std::cin >> ops2;
                    if (ops2 == 9) { break; }

                    if (indexNumber != 9) {
                        std::cout << std::endl;
                        std::cout
                                << "please choose your attack squad one by one via typing its index number.Untapped creature cards will be listed below"
                                << std::endl;
                        for (int i = 0; i < inPlay1.size(); i++) {
                            if (!inPlay1[i]->hasTappedInfo() && inPlay1[i]->getCardtype() == "CreatureCard") {
                                std::cout << i << ")" << inPlay1[i]->getCardName() << "  " << std::endl;
                            }
                        }
                        std::cin >> indexNumber;
                        squadIndexLog[mmm] = indexNumber;
                        mmm++;
                        inPlay1[indexNumber]->setTapped(mana1);

                        std::cout
                                << "if you are done with forming your attack squad please type 9 if you want to choose more for your attack squad please type 0"
                                << std::endl;
                        std::cin >> ops;
                        if (ops == 9) { done = true; }
                    }

                }
                if (player1->getHp() <= 0 || player2->getHp() <= 0) {printLoser(player1, player2, 3); break;}
                if (ops2 != 9) {

                    std::cout
                            << "dear opponent player, I mean player2, your opponent has formed its attack squad you are in danger!!! now you can choose your defence squad to arrange a welcome "
                            << std::endl;
                    std::cout << "they are " << mmm
                              << " many so you must choose that many defence card for your sake otherwise the excessive damage will effect your main HP if they can dominate your defence"
                              << std::endl;
                    std::cout << "below is the list of attackers " << std::endl;

                    for (int i = 0; i < mmm; i++) {
                        std::cout << inPlay1[squadIndexLog[i]]->getCardName() << std::endl;
                    }

                    std::cout << "below is the list of creature cards that you can choose for your defence squad "
                              << std::endl;
                    for (int i = 0; i < inPlay2.size(); i++) {
                        if (!inPlay2[i]->hasTappedInfo() && inPlay2[i]->getCardtype() == "CreatureCard") {
                            std::cout << i << ")" << inPlay2[i]->getCardName();
                        }
                    }


                    for (int i = 0; i < mmm; i++) {
                        std::cout << i << ". attacker is " << inPlay1[squadIndexLog[i]]->getCardName()
                                  << ". Choose your defender via typing its index number. To pass this attacker type 9"
                                  << std::endl;
                        std::cin >> ops;
                        if (ops == 9) { player2->susDamage(inPlay1[squadIndexLog[i]]->getAttackPower()); std::cout << "Player take " << inPlay1[squadIndexLog[i]]->getAttackPower() << " damage" << std::endl; }
                            // else{combat(inPlay1[squadIndexLog[i]],inPlay2[ops],player2);}
                        else { combat(inPlay1, squadIndexLog[i], inPlay2, ops, player2,discard1,discard2); }
                    }

                }

            } else {
                std::cout
                        << "player 1 dont have a creature card to attack because of that this phase ,chance for player1, will be simply passed"
                        << std::endl;
            }

            baseHp(inPlay1, library1, discard1, hand1);
            if (player1->getHp() <= 0 || player2->getHp() <= 0) {printLoser(player1, player2, 3); break;}
            //2. play phase for player1
            std::cout << std::endl;
            std::cout
                    << "----------------------------------2. PLAY PHASE FOR PLAYER 1 ----------------------------------"
                    << std::endl << std::endl;

            std::cout
                    << "now you can play your cards as possible your mana allows you but you can only play 1 land card"
                    << std::endl;

            std::cout << std::endl;

            while (true) {

                mana1->printMana();
                std::cout << "choose the cards below from your hand and type number of it to play it" << std::endl;

                std::cout << std::endl;

                auto it444=hand1.begin();
                int i = 0;

                for (it444 = hand1.begin(); it444 != hand1.end(); it444++) {
                    std::cout << i << ")";
                    (*it444)->printCardName();
                    std::cout << "  ";
                    i++;
                }

                std::cout << std::endl;

                std::cout << "type 9 to pass play phase " << std::endl;
                std::cin >> i;

                std::cout << std::endl;

                if(i==9){break;}
                else if (hand1[i]->isManaE(mana1)) {

                    std::vector<card>::iterator itXXX;

                    if (hand1[i]->getCardtype() == "LandCard") {
                        if (a < 1) {
                            a++;
                            std::cout << "Player1 played: " << hand1[i]->getCardName() << std::endl;hand1[i]->setTapped(mana1);
                            hand1[i]->play(mana1);
                            //(itXXX+i)->play(mana1);
                            inPlay1.emplace_back(hand1[i]);
                            hand1.erase(hand1.begin() + i);

                        } else {
                            std::cout << "you already have played land in 1. play phase of this round card you can not play 1 more" << std::endl;
                        }

                    } else if (hand1[i]->getCardtype() == "SorceryCard") {
                        std::cout << "Player1 played: " << hand1[i]->getCardName() << std::endl;
                        hand1[i]->play(mana1);

                        if (hand1[i]->getCardName() == "Disenchant") {
                            destroyCardEffectObj.destroyCardEffectFunc(inPlay2, discard2, hand1[i]->getCardName());
                        } else if (hand1[i]->getCardName() == "LightningBolt") {
                            dealDamageEffectObj.dealDamage(inPlay2, hand1[i]->getCardName(), player2);
                        } else if (hand1[i]->getCardName() == "Flood") {
                            destroyCardEffectObj.destroyCardEffectFunc(inPlay2, discard2, hand1[i]->getCardName());
                        } else if (hand1[i]->getCardName() == "Reanimate") {
                            reviveFromGraveEffectObj.revive(discard1, hand1);
                        } else if (hand1[i]->getCardName() == "Plague") {
                            dealDamageEffectObj.dealDamage(inPlay2, hand1[i]->getCardName(), player2);
                        } else if (hand1[i]->getCardName() == "Terror") {
                            destroyCardEffectObj.destroyCardEffectFunc(inPlay2, discard2, hand1[i]->getCardName());
                        }

                        inPlay1.emplace_back(hand1[i]);
                        hand1.erase(hand1.begin() + i);


                    } else if (hand1[i]->getCardtype() == "EnhancementCard") {
                        std::cout << "Player1 played: " << hand1[i]->getCardName() << std::endl;
                        hand1[i]->play(mana1);

                        if (hand1[i]->getCardName() == "Rage") {
                            abilityEffectObj.effectAbility(inPlay1, hand1[i]->getCardName());
                        } else if (hand1[i]->getCardName() == "HolyWar") {
                            effectForColorEffectObj.effectThatColorMembers(inPlay1, hand1[i]->getCardName());
                        } else if (hand1[i]->getCardName() == "HolyLight") {
                            effectForColorEffectObj.effectThatColorMembers(inPlay2, hand1[i]->getCardName());
                        } else if (hand1[i]->getCardName() == "UnholyWar") {
                            effectForColorEffectObj.effectThatColorMembers(inPlay1, hand1[i]->getCardName());
                        } else if (hand1[i]->getCardName() == "Restrain") {
                            abilityEffectObj.effectAbility(inPlay2, hand1[i]->getCardName());
                        } else if (hand1[i]->getCardName() == "Slow") {
                            abilityEffectObj.effectAbility(inPlay2, hand1[i]->getCardName());
                        }

                        inPlay1.emplace_back(hand1[i]);
                        hand1.erase(hand1.begin() + i);


                    } else {
                        std::cout << "Player1 played: " << hand1[i]->getCardName() << std::endl;
                        hand1[i]->play(mana1);
                        inPlay1.emplace_back(hand1[i]);
                        hand1.erase(hand1.begin() + i);
                    }

                } else { std::cout << "you dont have enough mana to play this Card" << std::endl; }
/*
                std::cout
                        << "You can tap your land cards if you want please choose and type a number which are given below. if there is no Land card then only option will be 9 please type 9 in this case"
                        << std::endl;
                std::cout << std::endl;

                int l = 0;

                for (int it333 = 0; it333 < inPlay1.size(); it333++) {
                    if (inPlay1[it333]->getCardtype() == "LandCard" && !inPlay1[it333]->hasTappedInfo()) {
                        std::cout << it333 << ")" << inPlay1[it333]->getCardName() << std::endl;
                        l++;
                    }
                    std::cout << "9) I'm done with tapping land cards" << std::endl;

                    int ll;
                    std::cin >> ll;
                    if (ll != 9) { for (int iii = 0; iii < l; iii++) { inPlay1[ll]->setTapped(mana1); }}
                    else if(ll=9){break;}




                }
                */
                std::cout << "to end this phase please type 9 to continue type 0 " << std::endl;
                int s;
                std::cin >> s;
                if (s == 9) { break; }
            }


            if (player1->getHp() <= 0 || player2->getHp() <= 0) {printLoser(player1, player2, 3); break;}

            baseHp(inPlay1, library1, discard1, hand1);

            //end phase for player1
            std::cout << std::endl;
            std::cout << "----------------------------------END PHASE----------------------------------"
                      << std::endl << std::endl;
            mana1->resetMana();


            std::cout << "All unused mana of the player is depleted. The turn is given to the opponent player"
                      << std::endl;

            if (player1->getHp() <= 0 || player2->getHp() <= 0) {printLoser(player1, player2, 3); break;}

            /////////////////////////////////ACTION FOR PLAYER2///////////////////////////////////////////


            if (player1->getHp() > 0 && player2->getHp() > 0) {

                baseHp(inPlay2, library2, discard2, hand2);

                //draw phase for player1
                std::cout << std::endl;
                std::cout << "----------------------------------DRAW PHASE----------------------------------" << std::endl
                          << std::endl;
                if (player1->getHp() <= 0 || player2->getHp() <= 0) {printLoser(player1, player2, 3); break;}

                if (library2.size() != 0 && hand2.size()<7) {
                    std::cout << "Player2 draw: " << library2[library2.size() - 1]->getCardName() << std::endl;
                    hand2.emplace_back(library2[library2.size() - 1]);
                    library2.pop_back();
                } else if (hand2.size() >= 7 && library2.size() != 0) {
                    std::cout
                            << "you have 7 cards in your hand its the limit you can not draw 1 more. Drawn card send to discard pile."
                            << std::endl << std::endl;
                    discard2.emplace_back(library2[library2.size() - 1]);
                    library2.pop_back();
                } else {
                    printLoser(player2, player1, 1);
                    break;
                }

                baseHp(inPlay2, library2, discard2, hand2);

                //untap phase for player1

                std::cout << std::endl;
                std::cout << "----------------------------------UNTAP PHASE FOR PLAYER 2 ----------------------------------"
                          << std::endl << std::endl;
                std::cout << "All tapped cards in play become once again untapped" << std::endl;

                untapped(inPlay2, library2, discard2, hand2);

                baseHp(inPlay2, library2, discard2, hand2);

                //play phase for player1
                std::cout << std::endl;
                std::cout << "----------------------------------PLAY PHASE FOR PLAYER 2 ----------------------------------"
                          << std::endl << std::endl;

                for(int i=0;i<inPlay2.size();i++){if(inPlay2[i]->getCardtype()=="LandCard"){inPlay2[i]->setTapped(mana2);}}
                std::cout
                        << "now you can play your cards as possible your mana allows you but you can only play 1 land card"
                        << std::endl;

                std::cout << std::endl;

                int a = 0;

                while (true) {

                    mana2->printMana();
                    std::cout << "choose the cards below from your hand and type number of it to play it" << std::endl;

                    std::cout << std::endl;

                    auto it444=hand2.begin();
                    int i = 0;

                    for (it444 = hand2.begin(); it444 != hand2.end(); it444++) {
                        std::cout << i << ")";
                        (*it444)->printCardName();
                        std::cout << "  ";
                        i++;
                    }

                    std::cout << std::endl;

                    std::cout << "type 9 to pass play phase " << std::endl;
                    std::cin >> i;

                    std::cout << std::endl;

                    if(i==9){break;}
                    else if (hand2[i]->isManaE(mana2)) {

                        std::vector<card>::iterator itXXX;

                        if (hand2[i]->getCardtype() == "LandCard") {
                            if (a < 1) {
                                a++;
                                std::cout << "Player2 played: " << hand2[i]->getCardName() << std::endl;hand2[i]->setTapped(mana2);
                                hand2[i]->play(mana2);
                                //(itXXX+i)->play(mana2);
                                inPlay2.emplace_back(hand2[i]);
                                hand2.erase(hand2.begin() + i);

                            } else {
                                std::cout << "you already have played land card you can not play 1 more" << std::endl;
                            }

                        } else if (hand2[i]->getCardtype() == "SorceryCard") {
                            std::cout << "Player2 played: " << hand2[i]->getCardName() << std::endl;
                            hand2[i]->play(mana2);

                            if (hand2[i]->getCardName() == "Disenchant") {
                                destroyCardEffectObj.destroyCardEffectFunc(inPlay1, discard1, hand2[i]->getCardName());
                            } else if (hand2[i]->getCardName() == "LightningBolt") {
                                dealDamageEffectObj.dealDamage(inPlay1, hand2[i]->getCardName(), player1);
                            } else if (hand2[i]->getCardName() == "Flood") {
                                destroyCardEffectObj.destroyCardEffectFunc(inPlay1, discard1, hand2[i]->getCardName());
                            } else if (hand2[i]->getCardName() == "Reanimate") {
                                reviveFromGraveEffectObj.revive(discard2, hand2);
                            } else if (hand2[i]->getCardName() == "Plague") {
                                dealDamageEffectObj.dealDamage(inPlay1, hand2[i]->getCardName(), player1);
                            } else if (hand2[i]->getCardName() == "Terror") {
                                destroyCardEffectObj.destroyCardEffectFunc(inPlay1, discard1, hand2[i]->getCardName());
                            }

                            inPlay2.emplace_back(hand2[i]);
                            hand2.erase(hand2.begin() + i);


                        } else if (hand2[i]->getCardtype() == "EnhancementCard") {
                            std::cout << "Player2 played: " << hand2[i]->getCardName() << std::endl;
                            hand2[i]->play(mana2);

                            if (hand2[i]->getCardName() == "Rage") {
                                abilityEffectObj.effectAbility(inPlay2, hand2[i]->getCardName());
                            } else if (hand2[i]->getCardName() == "HolyWar") {
                                effectForColorEffectObj.effectThatColorMembers(inPlay2, hand2[i]->getCardName());
                            } else if (hand2[i]->getCardName() == "HolyLight") {
                                effectForColorEffectObj.effectThatColorMembers(inPlay1, hand2[i]->getCardName());
                            } else if (hand2[i]->getCardName() == "UnholyWar") {
                                effectForColorEffectObj.effectThatColorMembers(inPlay2, hand2[i]->getCardName());
                            } else if (hand2[i]->getCardName() == "Restrain") {
                                abilityEffectObj.effectAbility(inPlay1, hand2[i]->getCardName());
                            } else if (hand2[i]->getCardName() == "Slow") {
                                abilityEffectObj.effectAbility(inPlay1, hand2[i]->getCardName());
                            }

                            inPlay2.emplace_back(hand2[i]);
                            hand2.erase(hand2.begin() + i);


                        } else {
                            std::cout << "Player2 played: " << hand2[i]->getCardName() << std::endl;
                            hand2[i]->play(mana2);
                            inPlay2.emplace_back(hand2[i]);
                            hand2.erase(hand2.begin() + i);
                        }

                    } else { std::cout << "you dont have enough mana to play this Card" << std::endl; }
                    if (player1->getHp() <= 0 || player2->getHp() <= 0) {printLoser(player1, player2, 3); break;}
/*
                std::cout
                        << "You can tap your land cards if you want please choose and type a number which are given below. if there is no Land card then only option will be 9 please type 9 in this case"
                        << std::endl;
                std::cout << std::endl;

                int l = 0;

                for (int it333 = 0; it333 < inPlay1.size(); it333++) {
                    if (inPlay1[it333]->getCardtype() == "LandCard" && !inPlay1[it333]->hasTappedInfo()) {
                        std::cout << it333 << ")" << inPlay1[it333]->getCardName() << std::endl;
                        l++;
                    }
                    std::cout << "9) I'm done with tapping land cards" << std::endl;

                    int ll;
                    std::cin >> ll;
                    if (ll != 9) { for (int iii = 0; iii < l; iii++) { inPlay1[ll]->setTapped(mana1); }}
                    else if(ll=9){break;}



                }
                */
                    std::cout << "to end this phase please type 9 to continue type 0 " << std::endl;
                    int s;
                    std::cin >> s;
                    if (s == 9) { break; }
                }

                baseHp(inPlay2, library2, discard2, hand2);

                //combat phase for player1
                std::cout << std::endl;
                std::cout
                        << "----------------------------------COMBAT PHASE FOR PLAYER 2 ----------------------------------"
                        << std::endl << std::endl;
                if (player1->getHp() <= 0 || player2->getHp() <= 0) {printLoser(player1, player2, 3); break;}
                int ops;

                int counter=0;
                for (int i = 0; i < inPlay2.size(); i++) {
                    if (inPlay2[i]->getCardtype() == "CreatureCard") { counter++; }
                }

                if (counter > 0) {

                    std::cout
                            << "please choose your attack squad one by one via typing its index number.Untapped creature cards will be listed below"
                            << std::endl << std::endl;

                    for (int i = 0; i < inPlay2.size(); i++) {
                        if (!inPlay2[i]->hasTappedInfo() && inPlay2[i]->getCardtype() == "CreatureCard") {
                            std::cout << i << ")" << inPlay2[i]->getCardName() << "  ";
                        }
                    }

                    bool done = false;
                    int indexNumber;
                    int squadIndexLog[9];
                    int mmm = 0;

                    std::cout << std::endl;
                    std::cout
                            << "if you just want to pass and if you dont want to attack please type 9; if you type any number expect 9 you have to attack"
                            << std::endl;
                    int ops2;
                    while (!done) {


                        std::cin >> ops2;
                        if (ops2 == 9) { break; }

                        if (indexNumber != 9) {
                            std::cout << std::endl;
                            std::cout
                                    << "please choose your attack squad one by one via typing its index number.Untapped creature cards will be listed below"
                                    << std::endl;
                            for (int i = 0; i < inPlay2.size(); i++) {
                                if (!inPlay2[i]->hasTappedInfo() && inPlay2[i]->getCardtype() == "CreatureCard") {
                                    std::cout << i << ")" << inPlay2[i]->getCardName() << "  " << std::endl;
                                }
                            }
                            std::cin >> indexNumber;
                            squadIndexLog[mmm] = indexNumber;
                            mmm++;
                            inPlay2[indexNumber]->setTapped(mana2);

                            std::cout
                                    << "if you are done with forming your attack squad please type 9 if you want to choose more for your attack squad please type 0"
                                    << std::endl;
                            std::cin >> ops;
                            if (ops == 9) { done = true; }
                        }

                    }
                    if (player1->getHp() <= 0 || player2->getHp() <= 0) {printLoser(player1, player2, 3); break;}
                    if (ops2 != 9) {

                        std::cout
                                << "dear opponent player, I mean player1, your opponent has formed its attack squad you are in danger!!! now you can choose your defence squad to arrange a welcome "
                                << std::endl;
                        std::cout << "they are " << mmm
                                  << " many so you must choose that many defence card for your sake otherwise the excessive damage will effect your main HP if they can dominate your defence"
                                  << std::endl;
                        std::cout << "below is the list of attackers " << std::endl;

                        for (int i = 0; i < mmm; i++) {
                            std::cout << inPlay2[squadIndexLog[i]]->getCardName() << std::endl;
                        }

                        std::cout << "below is the list of creature cards that you can choose for your defence squad "
                                  << std::endl;
                        for (int i = 0; i < inPlay1.size(); i++) {
                            if (!inPlay1[i]->hasTappedInfo() && inPlay1[i]->getCardtype() == "CreatureCard") {
                                std::cout << i << ")" << inPlay1[i]->getCardName();
                            }
                        }


                        for (int i = 0; i < mmm; i++) {
                            std::cout << i << ". attacker is " << inPlay2[squadIndexLog[i]]->getCardName()
                                      << ". Choose your defender via typing its index number. To pass this attacker type 9"
                                      << std::endl;
                            std::cin >> ops;
                            if (ops == 9) { player1->susDamage(inPlay2[squadIndexLog[i]]->getAttackPower()); std::cout << "Player take " << inPlay2[squadIndexLog[i]]->getAttackPower() << " damage" << std::endl;}
                                // else{combat(inPlay2[squadIndexLog[i]],inPlay1[ops],player1);}
                            else { combat(inPlay2, squadIndexLog[i], inPlay1, ops, player1,discard2,discard1); }
                        }

                    }

                } else {
                    std::cout
                            << "player 2 dont have a creature card to attack because of that this phase ,chance for player1, will be simply passed"
                            << std::endl;
                }
                if (player1->getHp() <= 0 || player2->getHp() <= 0) {printLoser(player1, player2, 3); break;}
                baseHp(inPlay2, library2, discard2, hand2);

                //2. play phase for player2
                std::cout << std::endl;
                std::cout
                        << "----------------------------------2. PLAY PHASE FOR PLAYER 2 ----------------------------------"
                        << std::endl << std::endl;

                std::cout
                        << "now you can play your cards as possible your mana allows you but you can only play 1 land card"
                        << std::endl;

                std::cout << std::endl;

                while (true) {

                    mana2->printMana();
                    std::cout << "choose the cards below from your hand and type number of it to play it" << std::endl;

                    std::cout << std::endl;

                    auto it444=hand2.begin();
                    int i = 0;

                    for (it444 = hand2.begin(); it444 != hand2.end(); it444++) {
                        std::cout << i << ")";
                        (*it444)->printCardName();
                        std::cout << "  ";
                        i++;
                    }

                    std::cout << std::endl;

                    std::cout << "type 9 to pass play phase " << std::endl;
                    std::cin >> i;

                    std::cout << std::endl;
                    if (player1->getHp() <= 0 || player2->getHp() <= 0) {printLoser(player1, player2, 3); break;}

                    if(i==9){break;}
                    else if (hand2[i]->isManaE(mana2)) {

                        std::vector<card>::iterator itXXX;

                        if (hand2[i]->getCardtype() == "LandCard") {
                            if (a < 1) {
                                a++;
                                std::cout << "Player2 played: " << hand2[i]->getCardName() << std::endl;hand2[i]->setTapped(mana2);
                                hand2[i]->play(mana2);
                                //(itXXX+i)->play(mana2);
                                inPlay2.emplace_back(hand2[i]);
                                hand2.erase(hand2.begin() + i);

                            } else {
                                std::cout << "you already have played land in 1. play phase of this round card you can not play 1 more" << std::endl;
                            }

                        } else if (hand2[i]->getCardtype() == "SorceryCard") {
                            std::cout << "Player2 played: " << hand2[i]->getCardName() << std::endl;
                            hand2[i]->play(mana2);

                            if (hand2[i]->getCardName() == "Disenchant") {
                                destroyCardEffectObj.destroyCardEffectFunc(inPlay1, discard1, hand2[i]->getCardName());
                            } else if (hand2[i]->getCardName() == "LightningBolt") {
                                dealDamageEffectObj.dealDamage(inPlay1, hand2[i]->getCardName(), player1);
                            } else if (hand2[i]->getCardName() == "Flood") {
                                destroyCardEffectObj.destroyCardEffectFunc(inPlay1, discard1, hand2[i]->getCardName());
                            } else if (hand2[i]->getCardName() == "Reanimate") {
                                reviveFromGraveEffectObj.revive(discard2, hand2);
                            } else if (hand2[i]->getCardName() == "Plague") {
                                dealDamageEffectObj.dealDamage(inPlay1, hand2[i]->getCardName(), player1);
                            } else if (hand2[i]->getCardName() == "Terror") {
                                destroyCardEffectObj.destroyCardEffectFunc(inPlay1, discard1, hand2[i]->getCardName());
                            }

                            inPlay2.emplace_back(hand2[i]);
                            hand2.erase(hand2.begin() + i);


                        } else if (hand2[i]->getCardtype() == "EnhancementCard") {
                            std::cout << "Player2 played: " << hand2[i]->getCardName() << std::endl;
                            hand2[i]->play(mana2);

                            if (hand2[i]->getCardName() == "Rage") {
                                abilityEffectObj.effectAbility(inPlay2, hand2[i]->getCardName());
                            } else if (hand2[i]->getCardName() == "HolyWar") {
                                effectForColorEffectObj.effectThatColorMembers(inPlay2, hand2[i]->getCardName());
                            } else if (hand2[i]->getCardName() == "HolyLight") {
                                effectForColorEffectObj.effectThatColorMembers(inPlay1, hand2[i]->getCardName());
                            } else if (hand2[i]->getCardName() == "UnholyWar") {
                                effectForColorEffectObj.effectThatColorMembers(inPlay2, hand2[i]->getCardName());
                            } else if (hand2[i]->getCardName() == "Restrain") {
                                abilityEffectObj.effectAbility(inPlay1, hand2[i]->getCardName());
                            } else if (hand2[i]->getCardName() == "Slow") {
                                abilityEffectObj.effectAbility(inPlay1, hand2[i]->getCardName());
                            }

                            inPlay2.emplace_back(hand2[i]);
                            hand2.erase(hand2.begin() + i);


                        } else {
                            std::cout << "Player2 played: " << hand2[i]->getCardName() << std::endl;
                            hand2[i]->play(mana2);
                            inPlay2.emplace_back(hand2[i]);
                            hand2.erase(hand2.begin() + i);
                        }

                    } else { std::cout << "you dont have enough mana to play this Card" << std::endl; }
/*
                std::cout
                        << "You can tap your land cards if you want please choose and type a number which are given below. if there is no Land card then only option will be 9 please type 9 in this case"
                        << std::endl;
                std::cout << std::endl;

                int l = 0;

                for (int it333 = 0; it333 < inPlay1.size(); it333++) {
                    if (inPlay1[it333]->getCardtype() == "LandCard" && !inPlay1[it333]->hasTappedInfo()) {
                        std::cout << it333 << ")" << inPlay1[it333]->getCardName() << std::endl;
                        l++;
                    }
                    std::cout << "9) I'm done with tapping land cards" << std::endl;

                    int ll;
                    std::cin >> ll;
                    if (ll != 9) { for (int iii = 0; iii < l; iii++) { inPlay1[ll]->setTapped(mana1); }}
                    else if(ll=9){break;}




                }
                */
                    std::cout << "to end this phase please type 9 to continue type 0 " << std::endl;
                    int s;
                    std::cin >> s;
                    if (s == 9) { break; }
                }


                baseHp(inPlay2, library2, discard2, hand2);

                //end phase for player2
                std::cout << std::endl;
                std::cout << "----------------------------------END PHASE----------------------------------"
                          << std::endl << std::endl;
                if (player1->getHp() <= 0 || player2->getHp() <= 0) {printLoser(player1, player2, 3); break;}
                mana2->resetMana();

                std::cout << "All unused mana of the player is depleted. The turn is given to the opponent player"
                          << std::endl;

                if (player1->getHp() <= 0 || player2->getHp() <= 0) {printLoser(player1, player2, 3); break;}

                std::cout<<std::endl<<std::endl<<std::endl << "***************************************END OF THE " << turnCounter << " ROUND*************************************"<<std::endl<<std::endl<<std::endl;
                turnCounter++;

            }
            else{
                printLoser(player1, player2, 3);
                break;
            }

        }}

    return 0;
}

//F35 25 milyon kod satırından oluşmaktadır.
//F35 consists of 25 million code lines.