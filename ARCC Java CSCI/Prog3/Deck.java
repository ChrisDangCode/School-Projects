import java.awt.event.*;
import java.util.Random;

import javax.swing.*;

public class Deck {
	
	// constants
	final int deckSize = 52 ;
	final int maxSuits = 4 ;
	final int maxCards = 13 ;
	final int HAND = 5 ;
		
	protected class Card {
		public int faceVal ;  // contains int values 1 - 13
		public int suit ;	  // contains int values 1 - 4 
		public boolean exist ;// shows if the card has been displayed
		
		public Card(int face, int suitNum){
			faceVal = face ;
			suit = suitNum ;
			exist = false ;
		} // end card constructor
		
		// function: setTrue
		// pre: none
		// post: sets the existance bool to true; helper function used to prevent duplicate cards 
		public void setTrue() {
			this.exist = true ;
		} // end setTrue
		
		// function: setFalse
		// pre: none
		// post: sets the existance bool to false; helper function used to reset cards
		public void setFalse() {
			this.exist = false ;
		} // end setTrue
		
	} // end Card class
	
	
	
	private Card[] Deck ;
	
	// A deck object consists of a Card array
	public Deck(){
		
		int cardCount = 0 ;
		Deck = new Card[deckSize] ;
		for (int i = 0; i < maxSuits; i++){	// sets up 13 cards of each suit
			for (int j = 0; j < maxCards; j++){
				Deck[cardCount] = new Card(j + 1, i + 1);
				++cardCount ;
			} // end for
		}
	} // end Deck constructor
	
	// function: draw
	// pre: none
	// post: returns an integer of 0 - 51 to represent 1 of 52 cards 
	public int draw() {
		// generates a value 0 - 51 to represent one
		// of the 52 cards available
		Random generator = new Random() ;
		return generator.nextInt(52) ;
	} // end draw
	
	// function: getExist
	// pre: must pass in Card object
	// post: returns a bool from the card to see if card has been displayed
	public boolean getExist(Card pick){
		return pick.exist ;
	}
	
	// function: getSuit
	// pre: must pass in Card object
	// post: returns a string of containing suit type of card
	public String getSuit(Card pick){

		switch (pick.suit)
		{
		case 1: return "Clubs" ;
		case 2: return "Hearts" ;
		case 3: return "Spades" ;
		case 4: return "Diamonds" ;
		} // end switch
		return "\n\n Suit type does not exist \n\n" ;
	} // end getSuit
	
	// function: getFaceVal
	// pre: must pass in Card object
	// post: returns a string of containing face value of card
	public String getFaceVal(Card pick) {

		switch (pick.faceVal)
		{
		case 1: return "  Ace" ;
		case 2: return "    2" ;
		case 3: return "    3" ;
		case 4: return "    4" ;
		case 5: return "    5" ;
		case 6: return "    6" ;
		case 7: return "    7" ;
		case 8: return "    8" ;
		case 9: return "    9" ;
		case 10: return "   10";
		case 11: return " Jack" ;
		case 12: return "Queen" ;
		case 13: return " King" ;
		} // end switch
		return "\n\n Face Value does not exist \n\n" ;
	} // end getFaceVal
	
	// function: getCard
	// pre: must pass in an integer
	// post: returns a a card from the deck object
	public Card getCard(int hold) {
		return Deck[hold] ;	
	} // end getCard
	
	// runs through deck to find matching card and returns the index
	public int getHold(Card c) {
		int count = 0 ;
		for (int i = 0 ; Deck[i].faceVal  != c.faceVal || Deck[i].suit != c.suit; i++){
			count++ ;
		} // end for
		return count ;
	} // end getHold
	
	
	// function: checkExists
	// pre: must pass in Card object
	// post: returns an integer for the card number
	public int checkExists(int hold) {
		while (this.getExist(this.getCard(hold))) 
			 hold = this.draw() ;
		this.getCard(hold).setTrue() ;
		return hold ;
		
	} // end checkExists 
	
	
	// function: display
		// pre: must pass in Card object
		// post: prints the card with suit and face value
	public void display(Card pick) {
		
		System.out.println(this.getFaceVal(pick) + " of " + this.getSuit(pick)); 
		//pick.exist = true ;
	} // end display
	
	// reset
	// pre: none
	// post: resets all the boolean values of the cards, similar to shuffling
	public void reset() {
		for (int i = 0, deckSize = 52; i < deckSize ; i++)
			Deck[i].setFalse();
	}

	// images of the cards
	static ImageIcon aceClubs = new ImageIcon("AceClubs.png") ;
	static ImageIcon aceDiamonds = new ImageIcon("AceDiamonds.png") ;
	static ImageIcon aceHearts = new ImageIcon("AceHearts.png") ;
	static ImageIcon aceSpades = new ImageIcon("AceSpades.png") ;
	static ImageIcon twoClubs = new ImageIcon("2Clubs.png") ;
	static ImageIcon twoDiamonds = new ImageIcon("2Diamonds.png") ;
	static ImageIcon twoHearts = new ImageIcon("2Hearts.png") ;
	static ImageIcon twoSpades = new ImageIcon("2Spades.png") ;
	static ImageIcon threeClubs = new ImageIcon("3Clubs.png") ;
	static ImageIcon threeDiamonds = new ImageIcon("3Diamonds.png") ;
	static ImageIcon threeHearts = new ImageIcon("3Hearts.png") ;
	static ImageIcon threeSpades = new ImageIcon("3Spades.png") ;
	static ImageIcon fourClubs = new ImageIcon("4Clubs.png") ;
	static ImageIcon fourDiamonds = new ImageIcon("4Diamonds.png") ;
	static ImageIcon fourHearts = new ImageIcon("4Hearts.png") ;
	static ImageIcon fourSpades = new ImageIcon("4Spades.png") ;
	static ImageIcon fiveClubs = new ImageIcon("5Clubs.png") ;
	static ImageIcon fiveDiamonds = new ImageIcon("5Diamonds.png") ;
	static ImageIcon fiveHearts = new ImageIcon("5Hearts.png") ;
	static ImageIcon fiveSpades = new ImageIcon("5Spades.png") ;
	static ImageIcon sixClubs = new ImageIcon("6Clubs.png") ;
	static ImageIcon sixDiamonds = new ImageIcon("6Diamonds.png") ;
	static ImageIcon sixHearts = new ImageIcon("6Hearts.png") ;
	static ImageIcon sixSpades = new ImageIcon("6Spades.png") ;
	static ImageIcon sevenClubs = new ImageIcon("7Clubs.png") ;
	static ImageIcon sevenDiamonds = new ImageIcon("7Diamonds.png") ;
	static ImageIcon sevenHearts = new ImageIcon("7Hearts.png") ;
	static ImageIcon sevenSpades = new ImageIcon("7Spades.png") ;
	static ImageIcon eightClubs = new ImageIcon("8Clubs.png") ;
	static ImageIcon eightDiamonds = new ImageIcon("8Diamonds.png") ;
	static ImageIcon eightHearts = new ImageIcon("8Hearts.png") ;
	static ImageIcon eightSpades = new ImageIcon("8Spades.png") ;
	static ImageIcon nineClubs = new ImageIcon("9Clubs.png") ;
	static ImageIcon nineDiamonds = new ImageIcon("9Diamonds.png") ;
	static ImageIcon nineHearts = new ImageIcon("9Hearts.png") ;
	static ImageIcon nineSpades = new ImageIcon("9Spades.png") ;
	static ImageIcon tenClubs = new ImageIcon("10Clubs.png") ;
	static ImageIcon tenDiamonds = new ImageIcon("10Diamonds.png") ;
	static ImageIcon tenHearts = new ImageIcon("10Hearts.png") ;
	static ImageIcon tenSpades = new ImageIcon("10Spades.png") ;
	static ImageIcon jackClubs = new ImageIcon("JackClubs.png") ;
	static ImageIcon jackDiamonds = new ImageIcon("JackDiamonds.png") ;
	static ImageIcon jackHearts = new ImageIcon("JackHearts.png") ;
	static ImageIcon jackSpades = new ImageIcon("JackSpades.png") ;
	static ImageIcon queenClubs = new ImageIcon("QueenClubs.png") ;
	static ImageIcon queenDiamonds = new ImageIcon("QueenDiamonds.png") ;
	static ImageIcon queenHearts = new ImageIcon("QueenHearts.png") ;
	static ImageIcon queenSpades = new ImageIcon("QueenSpades.png") ;
	static ImageIcon kingClubs = new ImageIcon("KingClubs.png") ;
	static ImageIcon kingDiamonds = new ImageIcon("KingDiamonds.png") ;
	static ImageIcon kingHearts = new ImageIcon("KingHearts.png") ;
	static ImageIcon kingSpades = new ImageIcon("KingSpades.png") ;
	
	// handCard
	// pre: must pass in an integer (0 - 51) that represents one of the cards form the deck
	// post: returns label that contains image
	 public static JLabel handCard(int hold) {
		
		JLabel label ;
		switch (hold)
		{
		case 0: return label = new JLabel(aceClubs);
		case 1: return label = new JLabel(twoClubs);
		case 2: return label = new JLabel(threeClubs);
		case 3: return label = new JLabel(fourClubs);
		case 4: return label = new JLabel(fiveClubs);
		case 5: return label = new JLabel(sixClubs);
		case 6: return label = new JLabel(sevenClubs);
		case 7: return label = new JLabel(eightClubs);
		case 8: return label = new JLabel(nineClubs);
		case 9: return label = new JLabel(tenClubs);
		case 10: return label = new JLabel(jackClubs);
		case 11: return label = new JLabel(queenClubs);
		case 12: return label = new JLabel(kingClubs);
		
		case 13: return label = new JLabel(aceHearts);
		case 14: return label = new JLabel(twoHearts);
		case 15: return label = new JLabel(threeHearts);
		case 16: return label = new JLabel(fourHearts);
		case 17: return label = new JLabel(fiveHearts);
		case 18: return label = new JLabel(sixHearts);
		case 19: return label = new JLabel(sevenHearts);
		case 20: return label = new JLabel(eightHearts);
		case 21: return label = new JLabel(nineHearts);
		case 22: return label = new JLabel(tenHearts);
		case 23: return label = new JLabel(jackHearts);
		case 24: return label = new JLabel(queenHearts);
		case 25: return label = new JLabel(kingHearts);
		
		case 26: return label = new JLabel(aceSpades);
		case 27: return label = new JLabel(twoSpades);
		case 28: return label = new JLabel(threeSpades);
		case 29: return label = new JLabel(fourSpades);
		case 30: return label = new JLabel(fiveSpades);
		case 31: return label = new JLabel(sixSpades);
		case 32: return label = new JLabel(sevenSpades);
		case 33: return label = new JLabel(eightSpades);
		case 34: return label = new JLabel(nineSpades);
		case 35: return label = new JLabel(tenSpades);
		case 36: return label = new JLabel(jackSpades);
		case 37: return label = new JLabel(queenSpades);
		case 38: return label = new JLabel(kingSpades);
		
		case 39: return label = new JLabel(aceDiamonds);
		case 40: return label = new JLabel(twoDiamonds);
		case 41: return label = new JLabel(threeDiamonds);
		case 42: return label = new JLabel(fourDiamonds);
		case 43: return label = new JLabel(fiveDiamonds);
		case 44: return label = new JLabel(sixDiamonds);
		case 45: return label = new JLabel(sevenDiamonds);
		case 46: return label = new JLabel(eightDiamonds);
		case 47: return label = new JLabel(nineDiamonds);
		case 48: return label = new JLabel(tenDiamonds);
		case 49: return label = new JLabel(jackDiamonds);
		case 50: return label = new JLabel(queenDiamonds);
		case 51: return label = new JLabel(kingDiamonds);
			
		} // end switch
		return label = new JLabel("Error - could not determine card.");
		
	} // end handCard
	
	 
	 
} // end Deck class
