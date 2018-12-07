//
// Created by sTaR pC on 06-Sep-18.
//

#ifndef PROJ_ANDROID_GAMELAYER_H
#define PROJ_ANDROID_GAMELAYER_H

#include "cocos2d.h"
#include "Deck.h"
#include "ui/CocosGUI.h"

USING_NS_CC;


class GameLayer : public Layer{

public:
    GameLayer();
    ~GameLayer();

    virtual bool init() override;
    static Scene* createScene();

    CREATE_FUNC(GameLayer);

    Size _screenSize;
    Sprite* _settingsHolder;

    int gameState;
    int currentCombinationArray[TOTAL_PLAYER_COUNT];
    int pointArray[TOTAL_PLAYER_COUNT];
    int dealerIndex;
    int dealerQue[TOTAL_PLAYER_COUNT];
    int dealCount;
    int lastRoundDealIndex;
    int currentSoundSetting;

    // FOR BUTTON CLICK REFERENCES
    Rect _cardRectSpaces[TOTAL_CARDS_PER_PLAYER];

    // UI STUFF
    Sprite* cardSpriteArray[TOTAL_CARDS_PER_PLAYER];
    Sprite* scoreCardSprite;
    Sprite* winnerCardSprite;
    Sprite* confirmationPanel;

    Sprite* otherPlayerViewCards[ SIZE_OTHER_VIEW_CARDS ]; // max number of view cards
    Sprite* faceDownCards[TOTAL_CARDS_PER_PLAYER * 3];

    ui::Button* _dealBtn;
    ui::Button* _playBtn;
    ui::Button* _sortBtn;

    std::vector<Vec2> bottomPositions;
    std::vector<Vec2> leftSidePositions;

    std::vector<float> bottomRotations;
    std::vector<float> leftRotations;

    //functions
    void restartGame();
    void resetHand();
    void revealDealCard(int playerIndex);

    void evaluateCurrentHandWinner();
    void calculateCombinationArray();
    void showWinnerCard();
    void acknowledgeCurrentDeal();

    void onSortBtnClick();
    void onPlayBtnClick();
    void onScoreCrossBtnClick();
    void onTestBestSortClick();
    void onTestShuffleClick();
    void onDealBtnClick();

    void sortCardsByPlayer(int playerIndex, SortingType sortingType);
    void showSettingsPanel();

    void setBestPossibleSetsForPlayer();
    void setBestPossibleAISet();
    void saveCurrentSet();

    void playCardMoveSound();
    void resetSettingsPanel();
    void showConfirmationPanel(ConfirmationPanelType type);
    void savePointArray();
    void showScoreCard();

private:
    Deck* _currentDeck;

    SortingType _currentSortingType;
    bool _isGameRunning;
    bool _isUIBusy;
    bool _isTouchingCard;
    bool _isAcknowledgementPending;
    bool _isAnimationFromMiddlePending;

    int _roundSettings;
    int _currentDealIndex;
    int _fixedCardSelection;
    int _currentHandWinner;
    int _currentHandTotalPoints;
    int _savedPlayerCardSet[TOTAL_CARDS_PER_PLAYER];

    void refreshGUI();
    void addPlayerCardToGUI(int, Card *, float px, float py);
    void initGame();

    bool onTouchBegan(cocos2d::Touch *touch, cocos2d::Event *event) override ;
    void onTouchMoved(cocos2d::Touch *touch, cocos2d::Event *event) override ;
    void onTouchEnded(cocos2d::Touch *touch, cocos2d::Event *event) override ;
    void onTouchCancelled(cocos2d::Touch *touch, cocos2d::Event *event) override ;

    void update(float dt) override ;
    void revealNextHand(bool isCalledByPlayer);
    void revealPlayerCard();
    void endGame();
    void modifyFaceDownCards(int playerIndex,int stoppingIndex);

    void animateCardFromMiddle();

    float getCardRoundingRotationValue(float posX, float pivotPoint);

    void setCardPositions(bool shiftIndex = false);

    void setCardPositionsForRound(bool shiftIndex = false);

    void moveIntoFixedPosition(bool isAnimate, int startPos = 0);

    void moveIntoFixedIndex();

    int getGUIIndexByID(int id);
};


#endif //PROJ_ANDROID_GAMELAYER_H
