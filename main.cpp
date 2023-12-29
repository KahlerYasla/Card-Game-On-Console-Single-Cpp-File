#include <iostream>
#include <vector>
#include <memory>
#include <cstdlib>
#include <ctime>
#include <stdlib.h>

//======================================================================================================================
/**
 * @class Mana
 * @brief Represents the mana pool of a player in a card game.
 *
 * The Mana class keeps track of the different types of mana (white, red, green, blue, black) that a player has.
 * It provides methods to reset the mana each turn, print the mana information, get user input for mana selection,
 * check if the mana is enough to play a card, and deduct mana when playing a card.
 *
 * The class also includes a map that stores the mana costs and requirements for each card in the game.
 * It provides methods to check if the player has enough mana for a card and to get the count of a specific type of mana.
 *
 * The Mana class can be inherited to add additional functionality or mana types.
 */
class Mana
{
protected:
    int whiteMana;
    int redMana;
    int greenMana;
    int blueMana;
    int blackMana;
    int colorlessManaSum;
    std::string cardName;

public:
    Mana() : whiteMana(1), redMana(1), greenMana(1), blueMana(1), blackMana(1), colorlessManaSum(whiteMana + redMana + greenMana + blueMana + blackMana) {}
    //----------------------------------------------------------------------------------------------------------------------
    /**
     * @brief Resets the mana value to its initial state.
     */
    void resetMana()
    {
        whiteMana = 0;
        redMana = 0;
        greenMana = 0;
        blueMana = 0;
        blackMana = 0;
    }
    //----------------------------------------------------------------------------------------------------------------------
    /**
     * @brief Prints the mana value.
     */
    void printMana()
    {
        std::cout << "White mana: " << whiteMana << " / "
                  << "Green mana: " << greenMana << " / "
                  << "Blue mana: " << blueMana << " / "
                  << "Red mana: " << redMana << " / "
                  << "Black mana: " << blackMana << std::endl;
    }
    //----------------------------------------------------------------------------------------------------------------------
    /**
     * @brief Retrieves the mana value.
     *
     * This function is used to get the mana value for a player in a card game.
     *
     * @return The mana value.
     */
    void getMana()
    {
        colorlessManaSum = whiteMana + redMana + greenMana + blueMana + blackMana;
        std::string temp;
        std::cout << "Choose whichever color of mana you want to use " << std::endl;
        std::cout << "R for red / W for white / G for green / L for blue / B for black " << std::endl;
        std::cin >> temp;

        if (temp == "R" && redMana > 0)
        {
            redMana--;
        }
        else if (temp == "R" && redMana <= 0)
        {
            std::cout << "You dont have enough mana. " << std::endl;
            getMana();
        }

        else if (temp == "W" && whiteMana > 0)
        {
            whiteMana--;
        }
        else if (temp == "W" && whiteMana <= 0)
        {
            std::cout << "You dont have enough mana. " << std::endl;
            getMana();
        }

        else if (temp == "G" && greenMana > 0)
        {
            greenMana--;
        }
        else if (temp == "G" && greenMana <= 0)
        {
            std::cout << "You dont have enough mana. " << std::endl;
            getMana();
        }

        else if (temp == "L" && blueMana > 0)
        {
            blueMana--;
        }
        else if (temp == "L" && blueMana <= 0)
        {
            std::cout << "You dont have enough mana. " << std::endl;
            getMana();
        }

        else if (temp == "B" && blackMana > 0)
        {
            blackMana--;
        }
        else if (temp == "B" && blackMana <= 0)
        {
            std::cout << "You dont have enough mana. " << std::endl;
            getMana();
        }
    }
    //----------------------------------------------------------------------------------------------------------------------
    /**
     * Calculates the cost of a card based on its name.
     *
     * @param cardName The name of the card.
     */
    void cost(const std::string &cardName)
    {
        const int colorlessManaSum = whiteMana + redMana + greenMana + blueMana + blackMana;

        // Map to store mana costs for each card
        std::unordered_map<std::string, std::vector<std::pair<std::string, int>>> manaCosts = {
            {"Soldier", {{"white", 1}}},
            {"ArmoredPegasus", {{"white", 1}, {"colorless", 1}}},
            {"WhiteKnight", {{"white", 2}}},
            {"AngryBear", {{"green", 1}, {"colorless", 2}}},
            {"Guard", {{"white", 2}, {"colorless", 2}}},
            // ... (continue for other cards)
        };

        auto it = manaCosts.find(cardName);
        if (it != manaCosts.end())
        {
            // Check if the player has enough mana for the card
            for (const auto &cost : it->second)
            {
                if (cost.first == "colorless" && cost.second <= colorlessManaSum)
                {
                    continue;
                }
                else if (cost.second > getManaCount(cost.first))
                {
                    std::cout << "Not enough mana for " << cardName << ". " << std::endl;
                    return;
                }
            }

            // Deduct the mana cost
            for (const auto &cost : it->second)
            {
                if (cost.first != "colorless")
                {
                    deductMana(cost.first);
                }
                else
                {
                    for (int i = 0; i < cost.second; ++i)
                    {
                        deductMana(cost.first);
                    }
                }
            }
        }
        else
        {
            std::cout << "Card " << cardName << " not found." << std::endl;
        }
    }
    //----------------------------------------------------------------------------------------------------------------------
    /**
     * Deducts mana of the specified type.
     *
     * @param manaType The type of mana to deduct.
     */
    void deductMana(const std::string &manaType)
    {
        if (manaType == "white")
        {
            whiteMana--;
        }
        else if (manaType == "red")
        {
            redMana--;
        }
        else if (manaType == "green")
        {
            greenMana--;
        }
        else if (manaType == "blue")
        {
            blueMana--;
        }
        else if (manaType == "black")
        {
            blackMana--;
        }
    }
    //----------------------------------------------------------------------------------------------------------------------
    /**
     * Checks if the mana is enough for a given card.
     *
     * @param cardName The name of the card.
     * @return True if the mana is enough, false otherwise.
     */
    bool isManaEnough(const std::string &cardName)
    {
        const int colorlessManaSum = whiteMana + redMana + greenMana + blueMana + blackMana;

        // Map to store mana requirements for each card
        std::unordered_map<std::string, std::vector<std::pair<std::string, int>>> manaRequirements = {
            {"Soldier", {{"white", 1}}},
            {"ArmoredPegasus", {{"white", 1}, {"colorless", 1}}},
            {"WhiteKnight", {{"white", 2}}},
            {"AngryBear", {{"green", 1}, {"colorless", 2}}},
            {"Guard", {{"white", 2}, {"colorless", 2}}},
            {"Werewolf", {{"white", 1}, {"green", 1}, {"colorless", 2}}},
            {"Skeleton", {{"black", 1}}},
            {"Ghost", {{"black", 1}, {"colorless", 1}}},
            {"BlackKnight", {{"black", 2}}},
            {"OrcManiac", {{"red", 1}, {"colorless", 2}}},
            {"Hobgoblin", {{"red", 1}, {"black", 1}, {"colorless", 1}}},
            {"Vampire", {{"black", 1}, {"colorless", 3}}},

            // Sorcery Cards
            {"Disenchant", {{"white", 1}, {"colorless", 1}}},
            {"LightningBolt", {{"green", 1}, {"colorless", 1}}},
            {"Flood", {{"white", 1}, {"green", 1}, {"colorless", 1}}},
            {"Reanimate", {{"black", 1}}},
            {"Plague", {{"black", 1}, {"colorless", 2}}},
            {"Terror", {{"black", 1}, {"colorless", 1}}},

            // Enchantment Cards
            {"Rage", {{"green", 1}}},
            {"HolyWar", {{"white", 1}, {"colorless", 1}}},
            {"HolyLight", {{"white", 1}, {"colorless", 1}}},
            {"UnholyWar", {{"black", 1}, {"colorless", 1}}},
            {"Restrain", {{"red", 1}, {"colorless", 2}}},
            {"Slow", {{"black", 1}}},

            // Basic Lands
            {"Plains", {{"colorless", 1}}},
            {"Island", {{"colorless", 1}}},
            {"Mountain", {{"colorless", 1}}},
            {"Swamp", {{"colorless", 1}}},
            {"Forest", {{"colorless", 1}}}};

        // Check if the card exists in the map
        auto it = manaRequirements.find(cardName);
        if (it != manaRequirements.end())
        {
            // Check if the player has enough mana for the card
            for (const auto &requirement : it->second)
            {
                if (requirement.first == "colorless" && requirement.second <= colorlessManaSum)
                {
                    continue;
                }
                else if (requirement.second > getManaCount(requirement.first))
                {
                    return false;
                }
            }
            return true;
        }

        return false; // Card not found in the map
    }
    //----------------------------------------------------------------------------------------------------------------------
    /**
     * @brief Get the count of mana of a specific type.
     *
     * @param manaType The type of mana to count.
     * @return The count of mana of the specified type.
     */
    int getManaCount(const std::string &manaType)
    {
        if (manaType == "white")
        {
            return whiteMana;
        }
        else if (manaType == "red")
        {
            return redMana;
        }
        else if (manaType == "green")
        {
            return greenMana;
        }
        else if (manaType == "blue")
        {
            return blueMana;
        }
        else if (manaType == "black")
        {
            return blackMana;
        }
        else
        {
            return 0;
        }
    }
    //----------------------------------------------------------------------------------------------------------------------
    /**
     * Increases the mana with tap for a given card.
     *
     * @param c The card for which the mana needs to be increased.
     */
    virtual void increaseManaWithTap(std::string c)
    {
        cardName = c;

        if (c == "Forest")
        {
            greenMana++;
        }
        else if (c == "Island")
        {
            blueMana++;
        }
        else if (c == "Mountain")
        {
            redMana++;
        }
        else if (c == "Plains")
        {
            whiteMana++;
        }
        else if (c == "Swamp")
        {
            blackMana++;
        }
    }
}; // Mana class
//======================================================================================================================
/**
 * @class Card
 * @brief Represents a card in a card game.
 *
 * The Card class provides functionality to create and manipulate cards in a card game.
 * It contains properties such as card name, type, and color, as well as various methods
 * for printing card information, modifying card stats, and performing card actions.
 * This class serves as a base class for specific types of cards in the game.
 */
class Card
{

protected:
    std::string cardName, cardType, cardColor;

public:
    Card() {}
    Card(std::string cN, std::string tP, std::string c) : cardName(cN), cardType(tP), cardColor(c) {}

    virtual void printCardName() { std::cout << cardName; }
    void printCardtype() { std::cout << cardType; }
    void printCardColor() { std::cout << cardColor; }

    std::string getCardName() { return cardName; }
    std::string getCardtype() { return cardType; }
    std::string getCardColor() { return cardColor; }

    virtual void BoostStats(){};
    virtual void DecreaseStats(){};
    virtual void BoostAttack(){};
    virtual void deal1Dmg(){};
    virtual void deal2Dmg(){};
    virtual void setUntapped(){};
    virtual void setTapped(std::unique_ptr<Mana> &mana){};
    virtual void setFirstStrike(){};
    virtual void setTrample(){};
    virtual void removeTrample(){};
    virtual void removeFirstStrike(){};
    virtual bool getFirstStrike() { return false; };
    virtual bool getTrample() { return false; };
    virtual void play(std::unique_ptr<Mana> &mana)
    {
        std::cout << "Card play function ";
        mana->cost(cardName);
    }
    virtual bool isManaE(std::unique_ptr<Mana> &mana) { return mana->isManaEnough(cardName); }
    virtual void goBaseHp(){};
    virtual bool hasTappedInfo() { return false; }

    virtual int getHp() { return 0; }
    virtual int getAttackPower() { return 0; }
    virtual void sustainDamage(int dmg) {}
    virtual bool checkDead() { return false; }

    virtual void trampleBase() {}
    virtual void firstStrikeBase() {}

    virtual void reverseHolyWar() {}
    virtual void reverseHolylight() {}
    virtual void reverseUnholyWar() {}
}; // Card class
//======================================================================================================================
/**
 * @brief The LandCard class represents a land card in a card game.
 *
 * It inherits from the Card class and adds functionality specific to land cards.
 */
class LandCard : public Card
{
protected:
    bool hasTapped;

public:
    /**
     * @brief Default constructor for LandCard.
     */
    LandCard() : Card(), hasTapped(0) {}

    /**
     * @brief Constructor for LandCard with specified parameters.
     *
     * @param cN The name of the card.
     * @param t The type of the card.
     * @param hT A boolean indicating whether the card has been tapped.
     */
    LandCard(std::string cN, std::string t, bool hT) : Card(cN, t, " "), hasTapped(hT) {}

    /**
     * @brief Plays the land card.
     *
     * @param mana A reference to a unique_ptr of Mana.
     */
    void play(std::unique_ptr<Mana> &mana)
    {
        std::cout << "land card play function ";
        mana->cost(cardName);
    }

    /**
     * @brief Prints the name of the card.
     */
    void printCardName() { std::cout << cardName; }

    /**
     * @brief Sets the land card as untapped.
     */
    void setUntapped() { hasTapped = false; }

    /**
     * @brief Sets the land card as tapped and increases mana with tap.
     *
     * @param mana A reference to a unique_ptr of Mana.
     */
    void setTapped(std::unique_ptr<Mana> &mana)
    {
        mana->increaseManaWithTap(cardName);
        hasTapped = true;
    }

    /**
     * @brief Checks if the land card has been tapped.
     *
     * @return true if the land card has been tapped, false otherwise.
     */
    bool hasTappedInfo() { return hasTapped; }

    /**
     * @brief Checks if the land card is a mana card.
     *
     * @return true if the land card is a mana card, false otherwise.
     */
    bool isManaE() { return true; }
}; // LandCard class
//======================================================================================================================
/**
 * @brief The CreatureCard class represents a card that is a creature in a card game.
 *
 * It inherits from the Card class and adds additional properties and methods specific to creature cards.
 */
class CreatureCard : public Card
{
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
    CreatureCard() : Card(), attackPower(0), baseHP(0), manaCost(" "), baseFirstStrike(0), baseTrample(0)
    {
    }
    CreatureCard(std::string cardName, std::string type, std::string color, int attack, int hp, std::string cost, bool firstStrike, bool trample) : Card(cardName, type, color), attackPower(attack), baseHP(hp), manaCost(cost), baseFirstStrike(firstStrike), baseTrample(trample)
    {
    }

    void play(std::unique_ptr<Mana> &mana) { mana->cost(cardName); }

    void printCardName() { std::cout << cardName; }
    void BoostStats()
    {
        attackPower++;
        hp++;
    }
    void DecreaseStats()
    {
        attackPower--;
        hp--;
    }
    void BoostAttack() { attackPower += 2; }

    void reverseHolyWar()
    {
        attackPower--;
        hp--;
    }
    void reverseHolylight()
    {
        attackPower++;
        hp++;
    }
    void reverseUnholyWar()
    {
        if (attackPower == 0 || attackPower < 0)
        {
        }
        else if (attackPower == 1)
        {
            attackPower--;
        }
        else
        {
            attackPower -= 2;
        }
    }

    void deal1Dmg() { hp--; }
    void deal2Dmg() { hp -= 2; }

    int dealAttack() { return attackPower; }

    void setUntapped() { hasTapped = false; }
    void setTapped() { hasTapped = true; }

    void setFirstStrike() { firstStrike = true; }
    void setTrample() { trample = true; }
    void removeTrample() { trample = false; }
    void removeFirstStrike() { firstStrike = false; }
    bool getFirstStrike() { return firstStrike; }
    bool getTrample() { return trample; }

    void trampleBase() { trample = baseTrample; }
    void firstStrikeBase() { firstStrike = baseFirstStrike; }

    void goBaseHp() { hp = baseHP; }

    bool hasTappedInfo() { return hasTapped; }

    bool isManaE(std::unique_ptr<Mana> &mana) { return mana->isManaEnough(cardName); }

    int getHp() { return hp; }
    int getAttackPower() { return attackPower; }
    void sustainDamage(int dmg) { hp -= dmg; }
    bool checkDead()
    {
        if (hp < 1)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
}; // CreatureCard class
//======================================================================================================================
/**
 * @brief The SorceryCard class represents a sorcery card in a card game.
 *
 * It inherits from the Card class and adds additional properties and methods specific to sorcery cards.
 */
class SorceryCard : public Card
{

protected:
    std::string effect2, manaCost2;

public:
    /**
     * @brief Default constructor for SorceryCard.
     */
    SorceryCard() : Card(), manaCost2(" "), effect2(" ") {}

    /**
     * @brief Constructor for SorceryCard.
     *
     * @param cN2 The name of the sorcery card.
     * @param cC2 The color of the sorcery card.
     * @param mC2 The mana cost of the sorcery card.
     * @param ef2 The effect of the sorcery card.
     */
    SorceryCard(std::string cN2, std::string cC2, std::string mC2, std::string ef2) : Card(cN2, "SorceryCard", cC2), manaCost2(mC2), effect2(ef2) {}

    /**
     * @brief Prints the name of the sorcery card.
     */
    void printCardName() { std::cout << cardName; }

    /**
     * @brief Plays the sorcery card using the provided mana.
     *
     * @param mana A reference to the mana object.
     */
    void play(std::unique_ptr<Mana> &mana) { mana->cost(cardName); }

    /**
     * @brief Checks if the mana is enough to play the sorcery card.
     *
     * @param mana A reference to the mana object.
     * @return True if the mana is enough, false otherwise.
     */
    bool isManaE(std::unique_ptr<Mana> &mana) { return mana->isManaEnough(cardName); }
}; // SorceryCard class
//======================================================================================================================
/**
 * @class EnhancementCard
 * @brief Represents an enhancement card in a card game.
 *
 * This class inherits from the Card class and adds additional properties and methods specific to enhancement cards.
 */
class EnhancementCard : public Card
{

protected:
    std::string effect2, manaCost2;

public:
    EnhancementCard() : Card(), manaCost2(" "), effect2(" ") {}
    EnhancementCard(std::string cN2, std::string cC2, std::string mC2, std::string ef2) : Card(cN2, "EnhancementCard", cC2), manaCost2(mC2), effect2(ef2) {}

    void printCardName() { std::cout << cardName; }
    void play(std::unique_ptr<Mana> &mana) { mana->cost(cardName); }
    bool isManaE(std::unique_ptr<Mana> &mana) { return mana->isManaEnough(cardName); }
}; // EnhancementCard class
//======================================================================================================================
/**
 * @class Player
 * @brief Represents a player in the card game.
 *
 * The Player class contains information about the player's health points (hp) and their card deck.
 * It provides methods for dealing damage, randomizing the deck, and getting the player's current hp.
 */
class Player
{

protected:
    int hp = 15;

    std::vector<std::shared_ptr<Card>> library;
    std::vector<std::shared_ptr<Card>> libraryx;
    std::vector<std::shared_ptr<Card>> hand;
    std::vector<std::shared_ptr<Card>> inPlay;
    std::vector<std::shared_ptr<Card>> discard;

public:
    Player() {}
    Player(std::vector<std::shared_ptr<Card>> &lib, std::vector<std::shared_ptr<Card>> &hnd, std::vector<std::shared_ptr<Card>> &iP, std::vector<std::shared_ptr<Card>> &dc) : library(lib), hand(hnd), inPlay(iP), discard(dc) { libaryRandomizeAndHand7Initialy(lib, hnd); }
    //----------------------------------------------------------------------------------------------------------------------
    void deal2Dmg() { hp -= 2; }
    //----------------------------------------------------------------------------------------------------------------------
    /**
     * Randomizes the cards in the library and deals 7 cards to the hand.
     *
     * @param lib The library of cards.
     * @param hnd The hand of cards.
     */
    void libaryRandomizeAndHand7Initialy(std::vector<std::shared_ptr<Card>> &lib, std::vector<std::shared_ptr<Card>> &hnd)
    {

        int a[26];

        for (int i = 0; i < 26; i++)
        {
            bool isUsedBefore = false;
            a[i] = (rand() % library.size());

            for (int j = 0; j < i; j++)
            {
                if (a[i] == a[j])
                {
                    isUsedBefore = true;
                }
            }

            if (!isUsedBefore)
            {
                libraryx.emplace_back(library[a[i]]);
            }
            else
            {
                i--;
            }
        }

        lib = library = libraryx;

        for (int i = 0; i < 5; i++)
        {
            hnd.emplace_back(lib[lib.size() - 1]);
            lib.pop_back();
        }
    }
    //----------------------------------------------------------------------------------------------------------------------
    void susDamage(int dmg) { hp -= dmg; }
    //----------------------------------------------------------------------------------------------------------------------
    int getHp() { return hp; }
}; // Player class
//======================================================================================================================
/**
 * @brief Represents an effect in the card game.
 *
 * This class is responsible for defining the behavior of an effect in the card game.
 * It serves as a base class for specific types of effects.
 */
class Effect
{
}; // Effect class
//======================================================================================================================
/**
 * @class DestroyCardEffect
 * @brief Represents an effect that destroys cards in a card game.
 *
 * The DestroyCardEffect class is a subclass of the Effect class and provides functionality
 * to destroy specific types of cards in the game. It allows the player to choose a card to destroy
 * from a given set of cards and performs the necessary actions based on the type of card destroyed.
 *
 * The DestroyCardEffect class contains a single public method, destroyCardEffectFunc, which takes
 * in the player's cards, the discard pile, and the type of card to destroy as parameters. It then
 * performs the necessary actions to destroy the chosen card and updates the game state accordingly.
 */
class DestroyCardEffect : public Effect
{
public:
    /**
     * @brief Destroys a specific type of card in the game.
     *
     * This method allows the player to choose a card of a specific type (e.g., EnhancementCard,
     * LandCard, CreatureCard) to destroy from the opponent's in-play cards. It prompts the player
     * to choose the card to destroy and performs the necessary actions based on the type of card destroyed.
     *
     * @param ip The opponent's in-play cards.
     * @param discard The discard pile.
     * @param s The type of card to destroy.
     */
    void destroyCardEffectFunc(std::vector<std::shared_ptr<Card>> &ip, std::vector<std::shared_ptr<Card>> &discard, std::string s)
    {
        // Implementation code...
    }
}; // DestroyCardEffect class
class DestroyCardEffect : public Effect
{
public:
    void destroyCardEffectFunc(std::vector<std::shared_ptr<Card>> &ip, std::vector<std::shared_ptr<Card>> &discard, std::string s)
    {

        auto it = ip.begin();
        bool isThereDestroyable = false;

        if (s == "Disenchant")
        {

            for (it = ip.begin(); it != ip.end(); it++)
            {
                if ((*it)->getCardtype() == "EnhancementCard")
                {
                    isThereDestroyable = true;
                }
            }
            if (isThereDestroyable)
            {
                std::cout << "please choose which Enhancement Card you want to destroy" << std::endl;

                int i = 0;

                for (it = ip.begin(); it != ip.end(); it++)
                {
                    if ((*it)->getCardtype() == "EnhancementCard")
                    {
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

                if (namen == "Rage")
                {
                    for (it = ip.begin(); it != ip.end(); it++)
                    {
                        (*it)->trampleBase();
                    }
                }

                else if (namen == "HolyWar")
                {
                    for (it = ip.begin(); it != ip.end(); it++)
                    {
                        (*it)->reverseHolyWar();
                    }
                }

                else if (namen == "HolyLight")
                {
                    for (it = ip.begin(); it != ip.end(); it++)
                    {
                        (*it)->reverseHolylight();
                    }
                }
                else if (namen == "UnholyWar")
                {
                    for (it = ip.begin(); it != ip.end(); it++)
                    {
                        (*it)->reverseUnholyWar();
                    }
                }
                else if (namen == "Restrain")
                {
                    for (it = ip.begin(); it != ip.end(); it++)
                    {
                        if ((*it)->getCardColor() == "Green")
                            (*it)->trampleBase();
                    }
                }
                else if (namen == "Slow")
                {
                    for (it = ip.begin(); it != ip.end(); it++)
                    {
                        (*it)->trampleBase();
                    }
                }

                discard.emplace_back(ip[i]);
                ip.erase(ip.begin() + i);
                isThereDestroyable = false;
            }
            else
            {
                std::cout
                    << "there is no destroyable enhancement card in opponents in play cards you have wasted your card"
                    << std::endl;
            }
        }
        else if (s == "Flood")
        {
            for (it = ip.begin(); it != ip.end(); it++)
            {
                if ((*it)->getCardtype() == "LandCard")
                {
                    isThereDestroyable = true;
                }
            }
            if (isThereDestroyable)
            {

                std::cout << "please choose which Land Card you want to destroy" << std::endl;

                int i = 0;

                for (it = ip.begin(); it != ip.end(); it++)
                {
                    if ((*it)->getCardtype() == "LandCard")
                    {
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
            }
            else
            {
                std::cout << "there is no destroyable land card in opponents in play cards you have wasted your card"
                          << std::endl;
                isThereDestroyable = false;
            }
        }
        else if (s == "Terror")
        {
            for (it = ip.begin(); it != ip.end(); it++)
            {
                if ((*it)->getCardtype() == "CreatureCard")
                {
                    isThereDestroyable = true;
                }
            }
            if (isThereDestroyable)
            {

                std::cout << "please choose which Creature Card you want to destroy" << std::endl;

                int i = 0;

                for (it = ip.begin(); it != ip.end(); it++)
                {
                    if ((*it)->getCardtype() == "CreatureCard")
                    {
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
            }
            else
            {
                std::cout
                    << "there is no destroyable creature card in opponents in play cards you have wasted your card"
                    << std::endl;
            }
        }
    }
}; // DestroyCardEffect class
//======================================================================================================================
// Effect card stats
class EffectForColorEffect : public Effect
{
public:
    void effectThatColorMembers(std::vector<std::shared_ptr<Card>> &ip, std::string s)
    {

        auto it = ip.begin();

        if (s == "HolyWar")
        {
            for (it = ip.begin(); it != ip.end(); it++)
            {
                if ((*it)->getCardColor() == "White")
                {
                    (*it)->BoostStats();
                }
            }
            std::cout << "all white creature cards in your side that in play gain +1/+1 " << std::endl;
        }

        else if (s == "HolyLight")
        {
            for (it = ip.begin(); it != ip.end(); it++)
            {
                if ((*it)->getCardColor() == "Black")
                {
                    (*it)->DecreaseStats();
                }
            }
            std::cout << "all black creature cards in your side that in play gain -1/-1 " << std::endl;
        }

        else if (s == "UnholyWar")
        {
            for (it = ip.begin(); it != ip.end(); it++)
            {
                if ((*it)->getCardColor() == "Black")
                {
                    (*it)->BoostAttack();
                }
            }
            std::cout << "all black creature cards in your side that in play gain +2/0 " << std::endl;
        }
    }
}; // EffectForColorEffect class
//======================================================================================================================
// Effect for dealing damage
class DealDamageEffect : public Effect
{
public:
    void dealDamage(std::vector<std::shared_ptr<Card>> &ip, std::string n, std::unique_ptr<Player> &player)
    {
        auto it = ip.begin();
        if (n == "Plague")
        {
            for (it = ip.begin(); it != ip.end(); it++)
            {
                (*it)->deal1Dmg();
            }
            std::cout << "all opponent's creature cards dealt 1 damage " << std::endl;
        }

        else if (n == "LightningBolt")
        {

            std::cout << "please choose given options below and type its number" << std::endl;
            std::cout << "1)Deal damage to player" << std::endl;
            std::cout << "2)Deal damage to target creature card" << std::endl;

            int a;

            std::cin >> a;

            if (a == 1)
            {
                player->deal2Dmg();
                std::cout << "dealt 2 damage to the opponent player" << std::endl;
            }

            else if (a == 2)
            {
                for (it = ip.begin(); it != ip.end(); it++)
                {
                    if ((*it)->getCardtype() == "CreatureCard")
                    {
                        (*it)->deal2Dmg();
                        std::cout << "dealt " << (*it)->getCardName() << " 2 damage " << std::endl;
                    }
                }
            }

            else
            {
                std::cout << "YOU HAVE MISSED YOUR CHANCE " << std::endl;
            }
        }
    }
}; // DealDamageEffect class
//======================================================================================================================
// Reanimate effect
class ReviveFromGraveEffect : public Effect
{
public:
    void revive(std::vector<std::shared_ptr<Card>> &discard, std::vector<std::shared_ptr<Card>> &hand)
    {

        auto it = discard.begin();

        int temp = 0;
        if (discard.size() <= 0)
        {
            std::cout << "you dont have any card in discard pile you have missed your chance" << std::endl;
        }
        else
        {
            std::cout << "Choose 1 creature card from your discard pile. " << std::endl;

            bool a = false;

            while (!a)
            {
                for (it = discard.begin(); it != discard.end(); it++)
                {
                    if (hand.size() < 7)
                    {

                        std::cout << temp << ")";
                        (*it)->printCardName();
                        temp++;
                    }
                    else
                    {
                        std::cout << "Your hand is full. You can not play this card." << std::endl;
                    }
                }

                std::cin >> temp;
                if (discard[temp]->getCardtype() == "CreatureCard")
                {
                    hand.emplace_back(discard[temp]);
                    discard.erase(discard.begin() + temp);
                    std::cout << (*it)->getCardName() << " card has moved to your hand." << std::endl;
                    a = true;
                }
                else
                {
                    std::cout << "Chosen card is not a creature card. Please choose one creature card." << std::endl;
                }
            }
        }
    }
}; // ReviveFromGraveEffect class
//======================================================================================================================
// Effect cards abilities
class AbilityEffect : public Effect
{
public:
    void effectAbility(std::vector<std::shared_ptr<Card>> &ip, std::string n)
    {
        auto it = ip.begin();
        int tmp = 0;

        if (n == "Restrain")
        {
            for (it = ip.begin(); it != ip.end(); it++)
            {
                if ((*it)->getCardColor() == "Green")
                {
                    (*it)->removeTrample();
                    std::cout << (*it)->getCardName() << "'s trample ability removed " << std::endl;
                }
            }
        }

        else if (n == "Rage")
        {
            std::cout << "Choose one target creature card. It will gain Trample effect" << std::endl;
            bool a = false;
            while (!a)
            {
                for (it = ip.begin(); it != ip.end(); it++)
                {
                    if ((*it)->getCardtype() == "CreatureCard")
                    {
                        std::cout << tmp << ")";
                        (*it)->printCardName();
                        tmp++;
                        std::cin >> tmp;

                        if ((*it)->getCardtype() == "CreatureCard")
                        {
                            (*it)->setTrample();
                            std::cout << (*it)->getCardName() << " gain trample ability " << std::endl;
                            a = true;
                        }
                        else
                        {
                            std::cout << "Chosen card is not a creature card. Please choose one creature card." << std::endl;
                        }
                    }
                    else
                    {
                        std::cout << "There is no available creature card " << std::endl;
                    }
                }
            }
        }

        else if (n == "Slow")
        {
            std::cout << "Choose one target creature card." << std::endl;
            bool a = false;
            while (!a)
            {
                for (it = ip.begin(); it != ip.end(); it++)
                {
                    if ((*it)->getCardtype() == "CreatureCard")
                    {
                        std::cout << tmp << ")";
                        (*it)->printCardName();
                        tmp++;
                        std::cin >> tmp;

                        if ((*it)->getCardtype() == "CreatureCard")
                        {
                            (*it)->removeFirstStrike();
                            std::cout << (*it)->getCardName() << "'s first strike ability removed " << std::endl;
                            a = true;
                        }
                        else
                        {
                            std::cout << "Chosen card is not a creature card. Please choose one creature card." << std::endl;
                        }
                    }
                    else
                    {
                        std::cout << "There is no available creature card " << std::endl;
                    }
                }
            }
        }
    }
}; // AbilityEffect class
//======================================================================================================================
// Functions
//----------------------------------------------------------------------------------------------------------------------
// Print end of game information
void printLoser(std::unique_ptr<Player> &player1, std::unique_ptr<Player> &player2, int m)
{
    std::string loser, winner;

    if (player1->getHp() < 0 || m == 1)
    {
        loser = "player1";
        winner = "player2";
        std::cout << loser << " defeated" << std::endl;
        std::cout << winner << " survived with " << player2->getHp() << " hp and he/she is the winner" << std::endl;
    }
    else if (player2->getHp() < 0 || m == 2)
    {
        loser = "player2";
        winner = "player1";
        std::cout << loser << " defeated" << std::endl;
        std::cout << winner << " survived with " << player1->getHp() << " hp and he/she is the winner" << std::endl;
    }
} // printLoser function
//----------------------------------------------------------------------------------------------------------------------
// Untap cards function
void untapped(std::vector<std::shared_ptr<Card>> &ip, std::vector<std::shared_ptr<Card>> &l, std::vector<std::shared_ptr<Card>> &d, std::vector<std::shared_ptr<Card>> &h)
{
    auto it = ip.begin();

    for (it = ip.begin(); it != ip.end(); it++)
    {
        (*it)->setUntapped();
    }
    for (it = l.begin(); it != l.end(); it++)
    {
        (*it)->setUntapped();
    }
    for (it = d.begin(); it != d.end(); it++)
    {
        (*it)->setUntapped();
    }
    for (it = h.begin(); it != h.end(); it++)
    {
        (*it)->setUntapped();
    }
} // untapped function
//----------------------------------------------------------------------------------------------------------------------
// Return creature card's hp to their baseHP
void baseHp(std::vector<std::shared_ptr<Card>> &ip, std::vector<std::shared_ptr<Card>> &l, std::vector<std::shared_ptr<Card>> &d, std::vector<std::shared_ptr<Card>> &h)
{
    auto it = ip.begin();

    for (it = ip.begin(); it != ip.end(); it++)
    {
        (*it)->goBaseHp();
    }
    for (it = l.begin(); it != l.end(); it++)
    {
        (*it)->goBaseHp();
    }
    for (it = d.begin(); it != d.end(); it++)
    {
        (*it)->goBaseHp();
    }
    for (it = h.begin(); it != h.end(); it++)
    {
        (*it)->goBaseHp();
    }
} // baseHp function
//----------------------------------------------------------------------------------------------------------------------
// Attack function of creature cards
void combat(std::vector<std::shared_ptr<Card>> &attackerInplay, int i, std::vector<std::shared_ptr<Card>> &defenderInplay, int o, std::unique_ptr<Player> &playerOp, std::vector<std::shared_ptr<Card>> &dc1, std::vector<std::shared_ptr<Card>> &dc2)
{

    int excessAttackPower;

    if (defenderInplay[o]->getCardtype() == "CreatureCard")
    {

        if (attackerInplay[i]->getFirstStrike())
        {
            defenderInplay[o]->sustainDamage(attackerInplay[i]->getAttackPower());
            std::cout << attackerInplay[i]->getCardName() << " hit " << attackerInplay[i]->getAttackPower() << " damage to " << defenderInplay[o]->getCardName() << std::endl;

            if (defenderInplay[o]->checkDead())
            {
                std::cout << defenderInplay[o]->getCardName() << " is destroyed " << std::endl;
                dc2.emplace_back(defenderInplay[o]);
                defenderInplay.erase(defenderInplay.begin() + o);
            }

            if (attackerInplay[i]->getAttackPower() < defenderInplay[o]->getHp())
            {
                attackerInplay[i]->sustainDamage(defenderInplay[o]->getAttackPower());
                std::cout << defenderInplay[o]->getCardName() << " hit " << defenderInplay[o]->getAttackPower() << " damage to " << attackerInplay[o]->getCardName() << std::endl;

                if (attackerInplay[i]->checkDead())
                {
                    std::cout << attackerInplay[i]->getCardName() << " is destroyed " << std::endl;
                    dc1.emplace_back(attackerInplay[i]);
                    attackerInplay.erase(attackerInplay.begin() + i);
                }
            }
        }

        else if (defenderInplay[o]->getFirstStrike())
        {
            attackerInplay[i]->sustainDamage(defenderInplay[o]->getAttackPower());
            std::cout << defenderInplay[o]->getCardName() << " hit " << defenderInplay[o]->getAttackPower() << " damage to " << attackerInplay[o]->getCardName() << std::endl;

            if (attackerInplay[i]->checkDead())
            {
                std::cout << attackerInplay[i]->getCardName() << " is destroyed " << std::endl;
                dc1.emplace_back(attackerInplay[i]);
                attackerInplay.erase(attackerInplay.begin() + i);
            }
            if (defenderInplay[o]->getAttackPower() < attackerInplay[i]->getHp())
            {
                defenderInplay[o]->sustainDamage(attackerInplay[i]->getAttackPower());
                std::cout << attackerInplay[i]->getCardName() << " hit " << attackerInplay[i]->getAttackPower() << " damage to " << defenderInplay[o]->getCardName() << std::endl;

                if (defenderInplay[o]->checkDead())
                {
                    std::cout << defenderInplay[o]->getCardName() << " is destroyed " << std::endl;
                    dc2.emplace_back(defenderInplay[o]);
                    defenderInplay.erase(defenderInplay.begin() + o);
                }
            }
        }

        else if (attackerInplay[i]->getFirstStrike() && defenderInplay[o]->getFirstStrike())
        {
            defenderInplay[o]->sustainDamage(attackerInplay[i]->getAttackPower());
            std::cout << attackerInplay[i]->getCardName() << " hit " << attackerInplay[i]->getAttackPower() << " damage to " << defenderInplay[o]->getCardName() << std::endl;

            attackerInplay[i]->sustainDamage(defenderInplay[o]->getAttackPower());
            std::cout << defenderInplay[o]->getCardName() << " hit " << defenderInplay[o]->getAttackPower() << " damage to " << attackerInplay[o]->getCardName() << std::endl;

            if (defenderInplay[o]->checkDead())
            {
                std::cout << defenderInplay[o]->getCardName() << " is destroyed " << std::endl;
                dc2.emplace_back(defenderInplay[o]);
                defenderInplay.erase(defenderInplay.begin() + o);
            }
            if (attackerInplay[i]->checkDead())
            {
                std::cout << attackerInplay[i]->getCardName() << " is destroyed " << std::endl;
                dc1.emplace_back(attackerInplay[i]);
                attackerInplay.erase(attackerInplay.begin() + i);
            }
        }

        else if (attackerInplay[i]->getTrample())
        {
            defenderInplay[o]->sustainDamage(defenderInplay[o]->getAttackPower());
            std::cout << attackerInplay[i]->getCardName() << " hit " << attackerInplay[i]->getAttackPower() << " damage to " << defenderInplay[o]->getCardName() << std::endl;

            attackerInplay[i]->sustainDamage(defenderInplay[o]->getAttackPower());
            std::cout << defenderInplay[o]->getCardName() << " hit " << defenderInplay[o]->getAttackPower() << " damage to " << attackerInplay[o]->getCardName() << std::endl;

            if (attackerInplay[i]->getAttackPower() > defenderInplay[o]->getHp())
            {
                excessAttackPower = attackerInplay[i]->getAttackPower() - defenderInplay[o]->getHp();
                playerOp->susDamage(excessAttackPower);
                std::cout << "Because of attacker card's trample ability " << excessAttackPower << " dealt to opponent player " << std::endl;
            }
        }

        else if (defenderInplay[o]->getTrample())
        {
            defenderInplay[o]->sustainDamage(attackerInplay[i]->getAttackPower());
            std::cout << attackerInplay[i]->getCardName() << " hit " << attackerInplay[i]->getAttackPower() << " damage to " << defenderInplay[o]->getCardName() << std::endl;

            attackerInplay[i]->sustainDamage(defenderInplay[o]->getAttackPower());
            std::cout << defenderInplay[o]->getCardName() << " hit " << defenderInplay[o]->getAttackPower() << " damage to " << attackerInplay[o]->getCardName() << std::endl;

            if (defenderInplay[o]->checkDead())
            {
                std::cout << defenderInplay[o]->getCardName() << " is destroyed " << std::endl;
                dc2.emplace_back(defenderInplay[o]);
                defenderInplay.erase(defenderInplay.begin() + o);
            }
            if (attackerInplay[i]->checkDead())
            {
                std::cout << attackerInplay[i]->getCardName() << " is destroyed " << std::endl;
                dc1.emplace_back(attackerInplay[i]);
                attackerInplay.erase(attackerInplay.begin() + i);
            }
        }

        else if (attackerInplay[i]->getFirstStrike() && attackerInplay[i]->getTrample())
        {
            defenderInplay[o]->sustainDamage(attackerInplay[i]->getAttackPower());
            std::cout << attackerInplay[i]->getCardName() << " hit " << attackerInplay[i]->getAttackPower() << " damage to " << defenderInplay[o]->getCardName() << std::endl;

            if (defenderInplay[o]->checkDead())
            {
                std::cout << defenderInplay[o]->getCardName() << " is destroyed " << std::endl;
                dc2.emplace_back(defenderInplay[o]);
                defenderInplay.erase(defenderInplay.begin() + o);
            }

            if (attackerInplay[i]->getAttackPower() < defenderInplay[o]->getHp())
            {
                attackerInplay[i]->sustainDamage(defenderInplay[o]->getAttackPower());
                std::cout << defenderInplay[o]->getCardName() << " hit " << defenderInplay[o]->getAttackPower() << " damage to " << attackerInplay[o]->getCardName() << std::endl;

                if (attackerInplay[i]->getAttackPower() > defenderInplay[o]->getHp())
                {
                    excessAttackPower = attackerInplay[i]->getAttackPower() - defenderInplay[o]->getHp();
                    playerOp->susDamage(excessAttackPower);
                    std::cout << "Because of attacker card's trample ability " << excessAttackPower << " dealt to opponent player " << std::endl;
                }
            }
        }

        else
        {
            defenderInplay[o]->sustainDamage(attackerInplay[i]->getAttackPower());
            std::cout << attackerInplay[i]->getCardName() << " hit " << attackerInplay[i]->getAttackPower() << " damage to " << defenderInplay[o]->getCardName() << std::endl;

            attackerInplay[i]->sustainDamage(defenderInplay[o]->getAttackPower());
            std::cout << defenderInplay[o]->getCardName() << " hit " << defenderInplay[o]->getAttackPower() << " damage to " << attackerInplay[o]->getCardName() << std::endl;

            if (defenderInplay[o]->checkDead())
            {
                std::cout << defenderInplay[o]->getCardName() << " is destroyed " << std::endl;
                dc2.emplace_back(defenderInplay[o]);
                defenderInplay.erase(defenderInplay.begin() + o);
            }
            if (attackerInplay[i]->checkDead())
            {
                std::cout << attackerInplay[i]->getCardName() << " is destroyed " << std::endl;
                dc1.emplace_back(attackerInplay[i]);
                attackerInplay.erase(attackerInplay.begin() + i);
            }
        }
    }
    else
    {
        std::cout << "Player take " << attackerInplay[i]->getAttackPower() << " damage" << std::endl;
        playerOp->susDamage(attackerInplay[i]->getAttackPower());
    }
} // combat function
//----------------------------------------------------------------------------------------------------------------------
// For print the cards in inPlay
void printInPlay(std::vector<std::shared_ptr<Card>> &ip)
{
    auto it = ip.begin();
    int counter = 0;
    std::cout << " cards that in play: " << std::endl;
    for (it = ip.begin(); it != ip.end(); it++)
    {
        std::cout << counter << ")" << (*it)->getCardName() << "  ";
        counter++;
    }
} // printInPlay function
//----------------------------------------------------------------------------------------------------------------------
// For print the cards in hand
void printHand(std::vector<std::shared_ptr<Card>> &hand)
{
    auto it = hand.begin();
    int counter = 0;
    std::cout << " cards that in hand: " << std::endl;
    for (it = hand.begin(); it != hand.end(); it++)
    {
        std::cout << counter << ")" << (*it)->getCardName() << "  ";
        counter++;
    }
} // printHand function
//======================================================================================================================
int main()
{
    srand(time(NULL));
    system("Color C");
    system("TREE");

    /// to form libraries

    std::vector<std::shared_ptr<Card>> library1;
    std::vector<std::shared_ptr<Card>> library2;

    /// to form hands

    std::vector<std::shared_ptr<Card>> hand1;
    std::vector<std::shared_ptr<Card>> hand2;

    /// to form inPlay

    std::vector<std::shared_ptr<Card>> inPlay1;
    std::vector<std::shared_ptr<Card>> inPlay2;

    /// to form discards

    std::vector<std::shared_ptr<Card>> discard1;
    std::vector<std::shared_ptr<Card>> discard2;

    /// to form manas
    std::unique_ptr<Mana> mana1 = std::make_unique<Mana>();
    std::unique_ptr<Mana> mana2 = std::make_unique<Mana>();

    /// to form effectObjects
    DestroyCardEffect destroyCardEffectObj;
    EffectForColorEffect effectForColorEffectObj;
    DealDamageEffect dealDamageEffectObj;
    ReviveFromGraveEffect reviveFromGraveEffectObj;
    AbilityEffect abilityEffectObj;

    /// Cards-----------------------------------------------------------------------------------------------------------------

    /// land cards

    std::shared_ptr<LandCard> forest1 = std::make_shared<LandCard>("Forest", "LandCard", 0);
    std::shared_ptr<LandCard> forest2 = std::make_shared<LandCard>("Forest", "LandCard", 0);
    std::shared_ptr<LandCard> forest3 = std::make_shared<LandCard>("Forest", "LandCard", 0);

    std::shared_ptr<LandCard> island = std::make_shared<LandCard>("Island", "LandCard", 0);

    std::shared_ptr<LandCard> mountain1 = std::make_shared<LandCard>("Mountain", "LandCard", 0);
    std::shared_ptr<LandCard> mountain2 = std::make_shared<LandCard>("Mountain", "LandCard", 0);
    std::shared_ptr<LandCard> mountain3 = std::make_shared<LandCard>("Mountain", "LandCard", 0);

    std::shared_ptr<LandCard> plains1 = std::make_shared<LandCard>("Plains", "LandCard", 0);
    std::shared_ptr<LandCard> plains2 = std::make_shared<LandCard>("Plains", "LandCard", 0);
    std::shared_ptr<LandCard> plains3 = std::make_shared<LandCard>("Plains", "LandCard", 0);
    std::shared_ptr<LandCard> plains4 = std::make_shared<LandCard>("Plains", "LandCard", 0);
    std::shared_ptr<LandCard> plains5 = std::make_shared<LandCard>("Plains", "LandCard", 0);

    std::shared_ptr<LandCard> swamp1 = std::make_shared<LandCard>("Swamp", "LandCard", 0);
    std::shared_ptr<LandCard> swamp2 = std::make_shared<LandCard>("Swamp", "LandCard", 0);
    std::shared_ptr<LandCard> swamp3 = std::make_shared<LandCard>("Swamp", "LandCard", 0);
    std::shared_ptr<LandCard> swamp4 = std::make_shared<LandCard>("Swamp", "LandCard", 0);
    std::shared_ptr<LandCard> swamp5 = std::make_shared<LandCard>("Swamp", "LandCard", 0);

    /// creature cards

    std::shared_ptr<CreatureCard> soldier1 = std::make_shared<CreatureCard>("Soldier", "CreatureCard", "White", 1, 1,
                                                                            "W", false, false);
    std::shared_ptr<CreatureCard> soldier2 = std::make_shared<CreatureCard>("Soldier", "CreatureCard", "White", 1, 1,
                                                                            "W", false, false);
    std::shared_ptr<CreatureCard> soldier3 = std::make_shared<CreatureCard>("Soldier", "CreatureCard", "White", 1, 1,
                                                                            "W", false, false);

    std::shared_ptr<CreatureCard> armoredPegasus1 = std::make_shared<CreatureCard>("ArmoredPegasus", "CreatureCard",
                                                                                   "White", 1, 2, "1W", false, false);
    std::shared_ptr<CreatureCard> armoredPegasus2 = std::make_shared<CreatureCard>("ArmoredPegasus", "CreatureCard",
                                                                                   "White", 1, 2, "1W", false, false);

    std::shared_ptr<CreatureCard> whiteKnight1 = std::make_shared<CreatureCard>("WhiteKnight", "CreatureCard", "White",
                                                                                2, 2, "WW", true, false);
    std::shared_ptr<CreatureCard> whiteKnight2 = std::make_shared<CreatureCard>("WhiteKnight", "CreatureCard", "White",
                                                                                2, 2, "WW", true, false);

    std::shared_ptr<CreatureCard> angryBear = std::make_shared<CreatureCard>("AngryBear", "CreatureCard", "Green", 3, 2,
                                                                             "2G", false, true);

    std::shared_ptr<CreatureCard> guard = std::make_shared<CreatureCard>("Guard", "CreatureCard", "White", 2, 5, "2WW",
                                                                         false, false);

    std::shared_ptr<CreatureCard> werewolf = std::make_shared<CreatureCard>("Werewolf", "CreatureCard", "Green", 4, 6,
                                                                            "2GW", false, true);

    std::shared_ptr<CreatureCard> skeleton1 = std::make_shared<CreatureCard>("Skeleton", "CreatureCard", "Black", 1, 1,
                                                                             "B", false, false);
    std::shared_ptr<CreatureCard> skeleton2 = std::make_shared<CreatureCard>("Skeleton", "CreatureCard", "Black", 1, 1,
                                                                             "B", false, false);
    std::shared_ptr<CreatureCard> skeleton3 = std::make_shared<CreatureCard>("Skeleton", "CreatureCard", "Black", 1, 1,
                                                                             "B", false, false);

    std::shared_ptr<CreatureCard> ghost1 = std::make_shared<CreatureCard>("Ghost", "CreatureCard", "Black", 2, 1, "1B",
                                                                          false, false);
    std::shared_ptr<CreatureCard> ghost2 = std::make_shared<CreatureCard>("Ghost", "CreatureCard", "Black", 2, 1, "1B",
                                                                          false, false);

    std::shared_ptr<CreatureCard> blackKnight1 = std::make_shared<CreatureCard>("BlackKnight", "CreatureCard", "Black",
                                                                                2, 2, "BB", true, false);
    std::shared_ptr<CreatureCard> blackKnight2 = std::make_shared<CreatureCard>("BlackKnight", "CreatureCard", "Black",
                                                                                2, 2, "BB", true, false);

    std::shared_ptr<CreatureCard> orcManiac = std::make_shared<CreatureCard>("OrcManiac", "CreatureCard", "Red", 4, 1,
                                                                             "2R", false, false);

    std::shared_ptr<CreatureCard> hobgoblin = std::make_shared<CreatureCard>("Hobgoblin", "CreatureCard", "Red", 3, 3,
                                                                             "1RB", false, false);

    std::shared_ptr<CreatureCard> vampire = std::make_shared<CreatureCard>("Vampire", "CreatureCard", "Black", 6, 3,
                                                                           "3B", false, false);

    // sorcery cards

    std::shared_ptr<SorceryCard> disenchant = std::make_shared<SorceryCard>("Disenchant", "White", "1W",
                                                                            "Destroy 1 Target Enchantment");

    std::shared_ptr<SorceryCard> lightningBolt = std::make_shared<SorceryCard>("LightningBolt", "Green", "1G",
                                                                               "Deal 2 dmg to target creature or player");

    std::shared_ptr<SorceryCard> flood1 = std::make_shared<SorceryCard>("Flood", "Green", "1GW",
                                                                        "Destroy 1 Target Land");
    std::shared_ptr<SorceryCard> flood2 = std::make_shared<SorceryCard>("Flood", "Green", "1GW",
                                                                        "Destroy 1 Target Land");

    std::shared_ptr<SorceryCard> reanimate = std::make_shared<SorceryCard>("Reanimate", "Black", "B",
                                                                           "Return 1 character card from discard to hand");

    std::shared_ptr<SorceryCard> plague = std::make_shared<SorceryCard>("Plague", "Black", "2B",
                                                                        "Deal 1 dmg to all creatures");

    std::shared_ptr<SorceryCard> terror1 = std::make_shared<SorceryCard>("Terror", "Black", "1B",
                                                                         "Destroy 1 Target Creature");
    std::shared_ptr<SorceryCard> terror2 = std::make_shared<SorceryCard>("Terror", "Black", "1B",
                                                                         "Destroy 1 Target Creature");

    // enchantment cards

    std::shared_ptr<EnhancementCard> rage = std::make_shared<EnhancementCard>("Rage", "Green", "G",
                                                                              "1 Target creature gains Trample");

    std::shared_ptr<EnhancementCard> holyWar = std::make_shared<EnhancementCard>("HolyWar", "White", "1W",
                                                                                 "All white creatures gain +1/+1");

    std::shared_ptr<EnhancementCard> holyLight = std::make_shared<EnhancementCard>("HolyLight", "White", "1W",
                                                                                   "All black creatures gain -1/-1");

    std::shared_ptr<EnhancementCard> unholyWar = std::make_shared<EnhancementCard>("UnholyWar", "Black", "1B",
                                                                                   "All black creatures gain +2/+0");

    std::shared_ptr<EnhancementCard> restrain = std::make_shared<EnhancementCard>("Restrain", "Red", "2R",
                                                                                  "All green creatures lose Trample");

    std::shared_ptr<EnhancementCard> slow = std::make_shared<EnhancementCard>("Slow", "Black", "B",
                                                                              "1 Target creature loses First Strike");

    //----------------------------------------------------------------------------------------------------------------------

    /// lib1

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

    /// lib2

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
    std::unique_ptr<Player> player1 = std::make_unique<Player>(library1, hand1, inPlay1, discard1);
    std::unique_ptr<Player> player2 = std::make_unique<Player>(library2, hand2, inPlay2, discard2);

    // Action----------------------------------------------------------------------------------------------------------------

    std::cout << "*** For a better gaming experience use the table that shows the game cards and their features. 233*** OO1" << std::endl
              << std::endl;

    int turnCounter = 1;

    while (true)
    {

        /////////////////////////////////ACTİON FOR PLAYER1///////////////////////////////////////////

        if (player1->getHp() > 0 && player2->getHp() > 0)
        {

            baseHp(inPlay1, library1, discard1, hand1);
            // Print players hp at each start of turn
            std::cout << "Player1's hp: " << player1->getHp() << "  Player2's hp: " << player2->getHp() << std::endl
                      << std::endl;

            // Print cards that in play for player1
            std::cout << "Player1's: ";
            printInPlay(inPlay1);
            std::cout << std::endl;

            // Print cards that in play for player2
            std::cout << "Player2's: ";
            printInPlay(inPlay2);
            std::cout << std::endl;

            // draw phase for player1
            std::cout << std::endl;
            std::cout << "----------------------------------DRAW PHASE----------------------------------" << std::endl
                      << std::endl;

            if (library1.size() != 0 && hand1.size() < 7)
            {
                std::cout << "Player1 draw: " << library1[library1.size() - 1]->getCardName() << std::endl;
                hand1.emplace_back(library1[library1.size() - 1]);
                library1.pop_back();
            }
            else if (hand1.size() >= 7 && library1.size() != 0)
            {
                std::cout
                    << "you have 7 cards in your hand its the limit you can not draw 1 more. Drawn card send to discard pile."
                    << std::endl
                    << std::endl;
                discard1.emplace_back(library1[library1.size() - 1]);
                library1.pop_back();
            }
            else
            {
                printLoser(player1, player2, 1);
                break;
            }

            baseHp(inPlay1, library1, discard1, hand1);
            if (player1->getHp() <= 0 || player2->getHp() <= 0)
            {
                printLoser(player1, player2, 3);
                break;
            }
            // untap phase for player1

            std::cout << std::endl;
            std::cout << "----------------------------------UNTAP PHASE FOR PLAYER 1 ----------------------------------"
                      << std::endl
                      << std::endl;
            std::cout << "All tapped cards in play become once again untapped" << std::endl;

            untapped(inPlay1, library1, discard1, hand1);

            baseHp(inPlay1, library1, discard1, hand1);
            if (player1->getHp() <= 0 || player2->getHp() <= 0)
            {
                printLoser(player1, player2, 3);
                break;
            }
            // play phase for player1
            std::cout << std::endl;
            std::cout << "----------------------------------PLAY PHASE FOR PLAYER 1 ----------------------------------"
                      << std::endl
                      << std::endl;

            for (int i = 0; i < inPlay1.size(); i++)
            {
                if (inPlay1[i]->getCardtype() == "LandCard")
                {
                    inPlay1[i]->setTapped(mana1);
                }
            }
            std::cout
                << "now you can play your cards as possible your mana allows you but you can only play 1 land card"
                << std::endl;

            std::cout << std::endl;

            int a = 0;

            while (true)
            {

                mana1->printMana();
                std::cout << "choose the cards below from your hand and type number of it to play it" << std::endl;

                std::cout << std::endl;

                auto it444 = hand1.begin();
                int i = 0;

                for (it444 = hand1.begin(); it444 != hand1.end(); it444++)
                {
                    std::cout << i << ")";
                    (*it444)->printCardName();
                    std::cout << "  ";
                    i++;
                }

                std::cout << std::endl;

                std::cout << "type 9 to pass play phase " << std::endl;
                std::cin >> i;

                std::cout << std::endl;
                if (player1->getHp() <= 0 || player2->getHp() <= 0)
                {
                    printLoser(player1, player2, 3);
                    break;
                }

                if (i == 9)
                {
                    break;
                }

                else if (hand1[i]->isManaE(mana1))
                {

                    std::vector<Card>::iterator itXXX;

                    if (hand1[i]->getCardtype() == "LandCard")
                    {
                        if (a < 1)
                        {
                            a++;
                            std::cout << "Player1 played: " << hand1[i]->getCardName() << std::endl;
                            hand1[i]->setTapped(mana1);
                            hand1[i]->play(mana1);
                            //(itXXX+i)->play(mana1);
                            inPlay1.emplace_back(hand1[i]);
                            hand1.erase(hand1.begin() + i);
                        }
                        else
                        {
                            std::cout << "you already have played land card you can not play 1 more" << std::endl;
                        }
                    }
                    else if (hand1[i]->getCardtype() == "SorceryCard")
                    {
                        std::cout << "Player1 played: " << hand1[i]->getCardName() << std::endl;
                        hand1[i]->play(mana1);

                        if (hand1[i]->getCardName() == "Disenchant")
                        {
                            destroyCardEffectObj.destroyCardEffectFunc(inPlay2, discard2, hand1[i]->getCardName());
                        }
                        else if (hand1[i]->getCardName() == "LightningBolt")
                        {
                            dealDamageEffectObj.dealDamage(inPlay2, hand1[i]->getCardName(), player2);
                        }
                        else if (hand1[i]->getCardName() == "Flood")
                        {
                            destroyCardEffectObj.destroyCardEffectFunc(inPlay2, discard2, hand1[i]->getCardName());
                        }
                        else if (hand1[i]->getCardName() == "Reanimate")
                        {
                            reviveFromGraveEffectObj.revive(discard1, hand1);
                        }
                        else if (hand1[i]->getCardName() == "Plague")
                        {
                            dealDamageEffectObj.dealDamage(inPlay2, hand1[i]->getCardName(), player2);
                        }
                        else if (hand1[i]->getCardName() == "Terror")
                        {
                            destroyCardEffectObj.destroyCardEffectFunc(inPlay2, discard2, hand1[i]->getCardName());
                        }

                        inPlay1.emplace_back(hand1[i]);
                        hand1.erase(hand1.begin() + i);
                    }
                    else if (hand1[i]->getCardtype() == "EnhancementCard")
                    {
                        std::cout << "Player1 played: " << hand1[i]->getCardName() << std::endl;
                        hand1[i]->play(mana1);

                        if (hand1[i]->getCardName() == "Rage")
                        {
                            abilityEffectObj.effectAbility(inPlay1, hand1[i]->getCardName());
                        }
                        else if (hand1[i]->getCardName() == "HolyWar")
                        {
                            effectForColorEffectObj.effectThatColorMembers(inPlay1, hand1[i]->getCardName());
                        }
                        else if (hand1[i]->getCardName() == "HolyLight")
                        {
                            effectForColorEffectObj.effectThatColorMembers(inPlay2, hand1[i]->getCardName());
                        }
                        else if (hand1[i]->getCardName() == "UnholyWar")
                        {
                            effectForColorEffectObj.effectThatColorMembers(inPlay1, hand1[i]->getCardName());
                        }
                        else if (hand1[i]->getCardName() == "Restrain")
                        {
                            abilityEffectObj.effectAbility(inPlay2, hand1[i]->getCardName());
                        }
                        else if (hand1[i]->getCardName() == "Slow")
                        {
                            abilityEffectObj.effectAbility(inPlay2, hand1[i]->getCardName());
                        }

                        inPlay1.emplace_back(hand1[i]);
                        hand1.erase(hand1.begin() + i);
                    }
                    else
                    {
                        std::cout << "Player1 played: " << hand1[i]->getCardName() << std::endl;
                        hand1[i]->play(mana1);
                        inPlay1.emplace_back(hand1[i]);
                        hand1.erase(hand1.begin() + i);
                    }
                    if (player1->getHp() <= 0 || player2->getHp() <= 0)
                    {
                        printLoser(player1, player2, 3);
                        break;
                    }
                }
                else
                {
                    std::cout << "you dont have enough mana to play this Card" << std::endl;
                }

                std::cout << "to end this phase please type 9 to continue type 0 " << std::endl;
                int s;
                std::cin >> s;
                if (s == 9)
                {
                    break;
                }
            }
            if (player1->getHp() <= 0 || player2->getHp() <= 0)
            {
                printLoser(player1, player2, 3);
                break;
            }
            baseHp(inPlay1, library1, discard1, hand1);

            // combat phase for player1
            std::cout << std::endl;
            std::cout
                << "----------------------------------COMBAT PHASE FOR PLAYER 1 ----------------------------------"
                << std::endl
                << std::endl;

            int ops;

            int counter = 0;
            for (int i = 0; i < inPlay1.size(); i++)
            {
                if (inPlay1[i]->getCardtype() == "CreatureCard")
                {
                    counter++;
                }
            }

            if (counter > 0)
            {

                std::cout
                    << "please choose your attack squad one by one via typing its index number.Untapped creature cards will be listed below"
                    << std::endl
                    << std::endl;

                for (int i = 0; i < inPlay1.size(); i++)
                {
                    if (!inPlay1[i]->hasTappedInfo() && inPlay1[i]->getCardtype() == "CreatureCard")
                    {
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
                while (!done)
                {

                    std::cin >> ops2;
                    if (ops2 == 9)
                    {
                        break;
                    }

                    if (indexNumber != 9)
                    {
                        std::cout << std::endl;
                        std::cout
                            << "please choose your attack squad one by one via typing its index number.Untapped creature cards will be listed below"
                            << std::endl;
                        for (int i = 0; i < inPlay1.size(); i++)
                        {
                            if (!inPlay1[i]->hasTappedInfo() && inPlay1[i]->getCardtype() == "CreatureCard")
                            {
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
                        if (ops == 9)
                        {
                            done = true;
                        }
                    }
                }
                if (player1->getHp() <= 0 || player2->getHp() <= 0)
                {
                    printLoser(player1, player2, 3);
                    break;
                }
                if (ops2 != 9)
                {

                    std::cout
                        << "dear opponent player, I mean player2, your opponent has formed its attack squad you are in danger!!! now you can choose your defence squad to arrange a welcome "
                        << std::endl;
                    std::cout << "they are " << mmm
                              << " many so you must choose that many defence card for your sake otherwise the excessive damage will effect your main HP if they can dominate your defence"
                              << std::endl;
                    std::cout << "below is the list of attackers " << std::endl;

                    for (int i = 0; i < mmm; i++)
                    {
                        std::cout << inPlay1[squadIndexLog[i]]->getCardName() << std::endl;
                    }

                    std::cout << "below is the list of creature cards that you can choose for your defence squad "
                              << std::endl;
                    for (int i = 0; i < inPlay2.size(); i++)
                    {
                        if (!inPlay2[i]->hasTappedInfo() && inPlay2[i]->getCardtype() == "CreatureCard")
                        {
                            std::cout << i << ")" << inPlay2[i]->getCardName();
                        }
                    }

                    for (int i = 0; i < mmm; i++)
                    {
                        std::cout << i << ". attacker is " << inPlay1[squadIndexLog[i]]->getCardName()
                                  << ". Choose your defender via typing its index number. To pass this attacker type 9"
                                  << std::endl;
                        std::cin >> ops;
                        if (ops == 9)
                        {
                            player2->susDamage(inPlay1[squadIndexLog[i]]->getAttackPower());
                            std::cout << "Player take " << inPlay1[squadIndexLog[i]]->getAttackPower() << " damage" << std::endl;
                        }
                        // else{combat(inPlay1[squadIndexLog[i]],inPlay2[ops],player2);}
                        else
                        {
                            combat(inPlay1, squadIndexLog[i], inPlay2, ops, player2, discard1, discard2);
                        }
                    }
                }
            }
            else
            {
                std::cout
                    << "player 1 dont have a creature card to attack because of that this phase ,chance for player1, will be simply passed"
                    << std::endl;
            }

            baseHp(inPlay1, library1, discard1, hand1);
            if (player1->getHp() <= 0 || player2->getHp() <= 0)
            {
                printLoser(player1, player2, 3);
                break;
            }
            // 2. play phase for player1
            std::cout << std::endl;
            std::cout
                << "----------------------------------2. PLAY PHASE FOR PLAYER 1 ----------------------------------"
                << std::endl
                << std::endl;

            std::cout
                << "now you can play your cards as possible your mana allows you but you can only play 1 land card"
                << std::endl;

            std::cout << std::endl;

            while (true)
            {

                mana1->printMana();
                std::cout << "choose the cards below from your hand and type number of it to play it" << std::endl;

                std::cout << std::endl;

                auto it444 = hand1.begin();
                int i = 0;

                for (it444 = hand1.begin(); it444 != hand1.end(); it444++)
                {
                    std::cout << i << ")";
                    (*it444)->printCardName();
                    std::cout << "  ";
                    i++;
                }

                std::cout << std::endl;

                std::cout << "type 9 to pass play phase " << std::endl;
                std::cin >> i;

                std::cout << std::endl;

                if (i == 9)
                {
                    break;
                }
                else if (hand1[i]->isManaE(mana1))
                {

                    std::vector<Card>::iterator itXXX;

                    if (hand1[i]->getCardtype() == "LandCard")
                    {
                        if (a < 1)
                        {
                            a++;
                            std::cout << "Player1 played: " << hand1[i]->getCardName() << std::endl;
                            hand1[i]->setTapped(mana1);
                            hand1[i]->play(mana1);
                            //(itXXX+i)->play(mana1);
                            inPlay1.emplace_back(hand1[i]);
                            hand1.erase(hand1.begin() + i);
                        }
                        else
                        {
                            std::cout << "you already have played land in 1. play phase of this round card you can not play 1 more" << std::endl;
                        }
                    }
                    else if (hand1[i]->getCardtype() == "SorceryCard")
                    {
                        std::cout << "Player1 played: " << hand1[i]->getCardName() << std::endl;
                        hand1[i]->play(mana1);

                        if (hand1[i]->getCardName() == "Disenchant")
                        {
                            destroyCardEffectObj.destroyCardEffectFunc(inPlay2, discard2, hand1[i]->getCardName());
                        }
                        else if (hand1[i]->getCardName() == "LightningBolt")
                        {
                            dealDamageEffectObj.dealDamage(inPlay2, hand1[i]->getCardName(), player2);
                        }
                        else if (hand1[i]->getCardName() == "Flood")
                        {
                            destroyCardEffectObj.destroyCardEffectFunc(inPlay2, discard2, hand1[i]->getCardName());
                        }
                        else if (hand1[i]->getCardName() == "Reanimate")
                        {
                            reviveFromGraveEffectObj.revive(discard1, hand1);
                        }
                        else if (hand1[i]->getCardName() == "Plague")
                        {
                            dealDamageEffectObj.dealDamage(inPlay2, hand1[i]->getCardName(), player2);
                        }
                        else if (hand1[i]->getCardName() == "Terror")
                        {
                            destroyCardEffectObj.destroyCardEffectFunc(inPlay2, discard2, hand1[i]->getCardName());
                        }

                        inPlay1.emplace_back(hand1[i]);
                        hand1.erase(hand1.begin() + i);
                    }
                    else if (hand1[i]->getCardtype() == "EnhancementCard")
                    {
                        std::cout << "Player1 played: " << hand1[i]->getCardName() << std::endl;
                        hand1[i]->play(mana1);

                        if (hand1[i]->getCardName() == "Rage")
                        {
                            abilityEffectObj.effectAbility(inPlay1, hand1[i]->getCardName());
                        }
                        else if (hand1[i]->getCardName() == "HolyWar")
                        {
                            effectForColorEffectObj.effectThatColorMembers(inPlay1, hand1[i]->getCardName());
                        }
                        else if (hand1[i]->getCardName() == "HolyLight")
                        {
                            effectForColorEffectObj.effectThatColorMembers(inPlay2, hand1[i]->getCardName());
                        }
                        else if (hand1[i]->getCardName() == "UnholyWar")
                        {
                            effectForColorEffectObj.effectThatColorMembers(inPlay1, hand1[i]->getCardName());
                        }
                        else if (hand1[i]->getCardName() == "Restrain")
                        {
                            abilityEffectObj.effectAbility(inPlay2, hand1[i]->getCardName());
                        }
                        else if (hand1[i]->getCardName() == "Slow")
                        {
                            abilityEffectObj.effectAbility(inPlay2, hand1[i]->getCardName());
                        }

                        inPlay1.emplace_back(hand1[i]);
                        hand1.erase(hand1.begin() + i);
                    }
                    else
                    {
                        std::cout << "Player1 played: " << hand1[i]->getCardName() << std::endl;
                        hand1[i]->play(mana1);
                        inPlay1.emplace_back(hand1[i]);
                        hand1.erase(hand1.begin() + i);
                    }
                }
                else
                {
                    std::cout << "you dont have enough mana to play this Card" << std::endl;
                }

                std::cout << "to end this phase please type 9 to continue type 0 " << std::endl;
                int s;
                std::cin >> s;
                if (s == 9)
                {
                    break;
                }
            }

            if (player1->getHp() <= 0 || player2->getHp() <= 0)
            {
                printLoser(player1, player2, 3);
                break;
            }

            baseHp(inPlay1, library1, discard1, hand1);

            // end phase for player1
            std::cout << std::endl;
            std::cout << "----------------------------------END PHASE----------------------------------"
                      << std::endl
                      << std::endl;
            mana1->resetMana();

            std::cout << "All unused mana of the player is depleted. The turn is given to the opponent player"
                      << std::endl;

            if (player1->getHp() <= 0 || player2->getHp() <= 0)
            {
                printLoser(player1, player2, 3);
                break;
            }

            /////////////////////////////////ACTION FOR PLAYER2///////////////////////////////////////////

            if (player1->getHp() > 0 && player2->getHp() > 0)
            {

                baseHp(inPlay2, library2, discard2, hand2);

                // draw phase for player1
                std::cout << std::endl;
                std::cout << "----------------------------------DRAW PHASE----------------------------------" << std::endl
                          << std::endl;
                if (player1->getHp() <= 0 || player2->getHp() <= 0)
                {
                    printLoser(player1, player2, 3);
                    break;
                }

                if (library2.size() != 0 && hand2.size() < 7)
                {
                    std::cout << "Player2 draw: " << library2[library2.size() - 1]->getCardName() << std::endl;
                    hand2.emplace_back(library2[library2.size() - 1]);
                    library2.pop_back();
                }
                else if (hand2.size() >= 7 && library2.size() != 0)
                {
                    std::cout
                        << "you have 7 cards in your hand its the limit you can not draw 1 more. Drawn card send to discard pile."
                        << std::endl
                        << std::endl;
                    discard2.emplace_back(library2[library2.size() - 1]);
                    library2.pop_back();
                }
                else
                {
                    printLoser(player2, player1, 1);
                    break;
                }

                baseHp(inPlay2, library2, discard2, hand2);

                // untap phase for player1

                std::cout << std::endl;
                std::cout << "----------------------------------UNTAP PHASE FOR PLAYER 2 ----------------------------------"
                          << std::endl
                          << std::endl;
                std::cout << "All tapped cards in play become once again untapped" << std::endl;

                untapped(inPlay2, library2, discard2, hand2);

                baseHp(inPlay2, library2, discard2, hand2);

                // play phase for player1
                std::cout << std::endl;
                std::cout << "----------------------------------PLAY PHASE FOR PLAYER 2 ----------------------------------"
                          << std::endl
                          << std::endl;

                for (int i = 0; i < inPlay2.size(); i++)
                {
                    if (inPlay2[i]->getCardtype() == "LandCard")
                    {
                        inPlay2[i]->setTapped(mana2);
                    }
                }
                std::cout
                    << "now you can play your cards as possible your mana allows you but you can only play 1 land card"
                    << std::endl;

                std::cout << std::endl;

                int a = 0;

                while (true)
                {

                    mana2->printMana();
                    std::cout << "choose the cards below from your hand and type number of it to play it" << std::endl;

                    std::cout << std::endl;

                    auto it444 = hand2.begin();
                    int i = 0;

                    for (it444 = hand2.begin(); it444 != hand2.end(); it444++)
                    {
                        std::cout << i << ")";
                        (*it444)->printCardName();
                        std::cout << "  ";
                        i++;
                    }

                    std::cout << std::endl;

                    std::cout << "type 9 to pass play phase " << std::endl;
                    std::cin >> i;

                    std::cout << std::endl;

                    if (i == 9)
                    {
                        break;
                    }
                    else if (hand2[i]->isManaE(mana2))
                    {

                        std::vector<Card>::iterator itXXX;

                        if (hand2[i]->getCardtype() == "LandCard")
                        {
                            if (a < 1)
                            {
                                a++;
                                std::cout << "Player2 played: " << hand2[i]->getCardName() << std::endl;
                                hand2[i]->setTapped(mana2);
                                hand2[i]->play(mana2);
                                //(itXXX+i)->play(mana2);
                                inPlay2.emplace_back(hand2[i]);
                                hand2.erase(hand2.begin() + i);
                            }
                            else
                            {
                                std::cout << "you already have played land card you can not play 1 more" << std::endl;
                            }
                        }
                        else if (hand2[i]->getCardtype() == "SorceryCard")
                        {
                            std::cout << "Player2 played: " << hand2[i]->getCardName() << std::endl;
                            hand2[i]->play(mana2);

                            if (hand2[i]->getCardName() == "Disenchant")
                            {
                                destroyCardEffectObj.destroyCardEffectFunc(inPlay1, discard1, hand2[i]->getCardName());
                            }
                            else if (hand2[i]->getCardName() == "LightningBolt")
                            {
                                dealDamageEffectObj.dealDamage(inPlay1, hand2[i]->getCardName(), player1);
                            }
                            else if (hand2[i]->getCardName() == "Flood")
                            {
                                destroyCardEffectObj.destroyCardEffectFunc(inPlay1, discard1, hand2[i]->getCardName());
                            }
                            else if (hand2[i]->getCardName() == "Reanimate")
                            {
                                reviveFromGraveEffectObj.revive(discard2, hand2);
                            }
                            else if (hand2[i]->getCardName() == "Plague")
                            {
                                dealDamageEffectObj.dealDamage(inPlay1, hand2[i]->getCardName(), player1);
                            }
                            else if (hand2[i]->getCardName() == "Terror")
                            {
                                destroyCardEffectObj.destroyCardEffectFunc(inPlay1, discard1, hand2[i]->getCardName());
                            }

                            inPlay2.emplace_back(hand2[i]);
                            hand2.erase(hand2.begin() + i);
                        }
                        else if (hand2[i]->getCardtype() == "EnhancementCard")
                        {
                            std::cout << "Player2 played: " << hand2[i]->getCardName() << std::endl;
                            hand2[i]->play(mana2);

                            if (hand2[i]->getCardName() == "Rage")
                            {
                                abilityEffectObj.effectAbility(inPlay2, hand2[i]->getCardName());
                            }
                            else if (hand2[i]->getCardName() == "HolyWar")
                            {
                                effectForColorEffectObj.effectThatColorMembers(inPlay2, hand2[i]->getCardName());
                            }
                            else if (hand2[i]->getCardName() == "HolyLight")
                            {
                                effectForColorEffectObj.effectThatColorMembers(inPlay1, hand2[i]->getCardName());
                            }
                            else if (hand2[i]->getCardName() == "UnholyWar")
                            {
                                effectForColorEffectObj.effectThatColorMembers(inPlay2, hand2[i]->getCardName());
                            }
                            else if (hand2[i]->getCardName() == "Restrain")
                            {
                                abilityEffectObj.effectAbility(inPlay1, hand2[i]->getCardName());
                            }
                            else if (hand2[i]->getCardName() == "Slow")
                            {
                                abilityEffectObj.effectAbility(inPlay1, hand2[i]->getCardName());
                            }

                            inPlay2.emplace_back(hand2[i]);
                            hand2.erase(hand2.begin() + i);
                        }
                        else
                        {
                            std::cout << "Player2 played: " << hand2[i]->getCardName() << std::endl;
                            hand2[i]->play(mana2);
                            inPlay2.emplace_back(hand2[i]);
                            hand2.erase(hand2.begin() + i);
                        }
                    }
                    else
                    {
                        std::cout << "you dont have enough mana to play this Card" << std::endl;
                    }
                    if (player1->getHp() <= 0 || player2->getHp() <= 0)
                    {
                        printLoser(player1, player2, 3);
                        break;
                    }

                    std::cout << "to end this phase please type 9 to continue type 0 " << std::endl;
                    int s;
                    std::cin >> s;
                    if (s == 9)
                    {
                        break;
                    }
                }

                baseHp(inPlay2, library2, discard2, hand2);

                // combat phase for player1
                std::cout << std::endl;
                std::cout
                    << "----------------------------------COMBAT PHASE FOR PLAYER 2 ----------------------------------"
                    << std::endl
                    << std::endl;
                if (player1->getHp() <= 0 || player2->getHp() <= 0)
                {
                    printLoser(player1, player2, 3);
                    break;
                }
                int ops;

                int counter = 0;
                for (int i = 0; i < inPlay2.size(); i++)
                {
                    if (inPlay2[i]->getCardtype() == "CreatureCard")
                    {
                        counter++;
                    }
                }

                if (counter > 0)
                {

                    std::cout
                        << "please choose your attack squad one by one via typing its index number.Untapped creature cards will be listed below"
                        << std::endl
                        << std::endl;

                    for (int i = 0; i < inPlay2.size(); i++)
                    {
                        if (!inPlay2[i]->hasTappedInfo() && inPlay2[i]->getCardtype() == "CreatureCard")
                        {
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
                    while (!done)
                    {

                        std::cin >> ops2;
                        if (ops2 == 9)
                        {
                            break;
                        }

                        if (indexNumber != 9)
                        {
                            std::cout << std::endl;
                            std::cout
                                << "please choose your attack squad one by one via typing its index number.Untapped creature cards will be listed below"
                                << std::endl;
                            for (int i = 0; i < inPlay2.size(); i++)
                            {
                                if (!inPlay2[i]->hasTappedInfo() && inPlay2[i]->getCardtype() == "CreatureCard")
                                {
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
                            if (ops == 9)
                            {
                                done = true;
                            }
                        }
                    }
                    if (player1->getHp() <= 0 || player2->getHp() <= 0)
                    {
                        printLoser(player1, player2, 3);
                        break;
                    }
                    if (ops2 != 9)
                    {

                        std::cout
                            << "dear opponent player, I mean player1, your opponent has formed its attack squad you are in danger!!! now you can choose your defence squad to arrange a welcome "
                            << std::endl;
                        std::cout << "they are " << mmm
                                  << " many so you must choose that many defence card for your sake otherwise the excessive damage will effect your main HP if they can dominate your defence"
                                  << std::endl;
                        std::cout << "below is the list of attackers " << std::endl;

                        for (int i = 0; i < mmm; i++)
                        {
                            std::cout << inPlay2[squadIndexLog[i]]->getCardName() << std::endl;
                        }

                        std::cout << "below is the list of creature cards that you can choose for your defence squad "
                                  << std::endl;
                        for (int i = 0; i < inPlay1.size(); i++)
                        {
                            if (!inPlay1[i]->hasTappedInfo() && inPlay1[i]->getCardtype() == "CreatureCard")
                            {
                                std::cout << i << ")" << inPlay1[i]->getCardName();
                            }
                        }

                        for (int i = 0; i < mmm; i++)
                        {
                            std::cout << i << ". attacker is " << inPlay2[squadIndexLog[i]]->getCardName()
                                      << ". Choose your defender via typing its index number. To pass this attacker type 9"
                                      << std::endl;
                            std::cin >> ops;
                            if (ops == 9)
                            {
                                player1->susDamage(inPlay2[squadIndexLog[i]]->getAttackPower());
                                std::cout << "Player take " << inPlay2[squadIndexLog[i]]->getAttackPower() << " damage" << std::endl;
                            }
                            // else{combat(inPlay2[squadIndexLog[i]],inPlay1[ops],player1);}
                            else
                            {
                                combat(inPlay2, squadIndexLog[i], inPlay1, ops, player1, discard2, discard1);
                            }
                        }
                    }
                }
                else
                {
                    std::cout
                        << "player 2 dont have a creature card to attack because of that this phase ,chance for player1, will be simply passed"
                        << std::endl;
                }
                if (player1->getHp() <= 0 || player2->getHp() <= 0)
                {
                    printLoser(player1, player2, 3);
                    break;
                }
                baseHp(inPlay2, library2, discard2, hand2);

                // 2. play phase for player2
                std::cout << std::endl;
                std::cout
                    << "----------------------------------2. PLAY PHASE FOR PLAYER 2 ----------------------------------"
                    << std::endl
                    << std::endl;

                std::cout
                    << "now you can play your cards as possible your mana allows you but you can only play 1 land card"
                    << std::endl;

                std::cout << std::endl;

                while (true)
                {

                    mana2->printMana();
                    std::cout << "choose the cards below from your hand and type number of it to play it" << std::endl;

                    std::cout << std::endl;

                    auto it444 = hand2.begin();
                    int i = 0;

                    for (it444 = hand2.begin(); it444 != hand2.end(); it444++)
                    {
                        std::cout << i << ")";
                        (*it444)->printCardName();
                        std::cout << "  ";
                        i++;
                    }

                    std::cout << std::endl;

                    std::cout << "type 9 to pass play phase " << std::endl;
                    std::cin >> i;

                    std::cout << std::endl;
                    if (player1->getHp() <= 0 || player2->getHp() <= 0)
                    {
                        printLoser(player1, player2, 3);
                        break;
                    }

                    if (i == 9)
                    {
                        break;
                    }
                    else if (hand2[i]->isManaE(mana2))
                    {

                        std::vector<Card>::iterator itXXX;

                        if (hand2[i]->getCardtype() == "LandCard")
                        {
                            if (a < 1)
                            {
                                a++;
                                std::cout << "Player2 played: " << hand2[i]->getCardName() << std::endl;
                                hand2[i]->setTapped(mana2);
                                hand2[i]->play(mana2);
                                //(itXXX+i)->play(mana2);
                                inPlay2.emplace_back(hand2[i]);
                                hand2.erase(hand2.begin() + i);
                            }
                            else
                            {
                                std::cout << "you already have played land in 1. play phase of this round card you can not play 1 more" << std::endl;
                            }
                        }
                        else if (hand2[i]->getCardtype() == "SorceryCard")
                        {
                            std::cout << "Player2 played: " << hand2[i]->getCardName() << std::endl;
                            hand2[i]->play(mana2);

                            if (hand2[i]->getCardName() == "Disenchant")
                            {
                                destroyCardEffectObj.destroyCardEffectFunc(inPlay1, discard1, hand2[i]->getCardName());
                            }
                            else if (hand2[i]->getCardName() == "LightningBolt")
                            {
                                dealDamageEffectObj.dealDamage(inPlay1, hand2[i]->getCardName(), player1);
                            }
                            else if (hand2[i]->getCardName() == "Flood")
                            {
                                destroyCardEffectObj.destroyCardEffectFunc(inPlay1, discard1, hand2[i]->getCardName());
                            }
                            else if (hand2[i]->getCardName() == "Reanimate")
                            {
                                reviveFromGraveEffectObj.revive(discard2, hand2);
                            }
                            else if (hand2[i]->getCardName() == "Plague")
                            {
                                dealDamageEffectObj.dealDamage(inPlay1, hand2[i]->getCardName(), player1);
                            }
                            else if (hand2[i]->getCardName() == "Terror")
                            {
                                destroyCardEffectObj.destroyCardEffectFunc(inPlay1, discard1, hand2[i]->getCardName());
                            }

                            inPlay2.emplace_back(hand2[i]);
                            hand2.erase(hand2.begin() + i);
                        }
                        else if (hand2[i]->getCardtype() == "EnhancementCard")
                        {
                            std::cout << "Player2 played: " << hand2[i]->getCardName() << std::endl;
                            hand2[i]->play(mana2);

                            if (hand2[i]->getCardName() == "Rage")
                            {
                                abilityEffectObj.effectAbility(inPlay2, hand2[i]->getCardName());
                            }
                            else if (hand2[i]->getCardName() == "HolyWar")
                            {
                                effectForColorEffectObj.effectThatColorMembers(inPlay2, hand2[i]->getCardName());
                            }
                            else if (hand2[i]->getCardName() == "HolyLight")
                            {
                                effectForColorEffectObj.effectThatColorMembers(inPlay1, hand2[i]->getCardName());
                            }
                            else if (hand2[i]->getCardName() == "UnholyWar")
                            {
                                effectForColorEffectObj.effectThatColorMembers(inPlay2, hand2[i]->getCardName());
                            }
                            else if (hand2[i]->getCardName() == "Restrain")
                            {
                                abilityEffectObj.effectAbility(inPlay1, hand2[i]->getCardName());
                            }
                            else if (hand2[i]->getCardName() == "Slow")
                            {
                                abilityEffectObj.effectAbility(inPlay1, hand2[i]->getCardName());
                            }

                            inPlay2.emplace_back(hand2[i]);
                            hand2.erase(hand2.begin() + i);
                        }
                        else
                        {
                            std::cout << "Player2 played: " << hand2[i]->getCardName() << std::endl;
                            hand2[i]->play(mana2);
                            inPlay2.emplace_back(hand2[i]);
                            hand2.erase(hand2.begin() + i);
                        }
                    }
                    else
                    {
                        std::cout << "you dont have enough mana to play this Card" << std::endl;
                    }
                    std::cout << "to end this phase please type 9 to continue type 0 " << std::endl;
                    int s;
                    std::cin >> s;
                    if (s == 9)
                    {
                        break;
                    }
                }

                baseHp(inPlay2, library2, discard2, hand2);

                // end phase for player2
                std::cout << std::endl;
                std::cout << "----------------------------------END PHASE----------------------------------"
                          << std::endl
                          << std::endl;
                if (player1->getHp() <= 0 || player2->getHp() <= 0)
                {
                    printLoser(player1, player2, 3);
                    break;
                }
                mana2->resetMana();

                std::cout << "All unused mana of the player is depleted. The turn is given to the opponent player"
                          << std::endl;

                if (player1->getHp() <= 0 || player2->getHp() <= 0)
                {
                    printLoser(player1, player2, 3);
                    break;
                }

                std::cout << std::endl
                          << std::endl
                          << std::endl
                          << "***************************************END OF THE " << turnCounter << " ROUND*************************************" << std::endl
                          << std::endl
                          << std::endl;
                turnCounter++;
            }
            else
            {
                printLoser(player1, player2, 3);
                break;
            }
        }
    }

    return 0;
}