import java.util.Random;

public class Deck {
	
	final int deckSize = 52 ;
	final int maxSuits = 4 ;
	final int maxCards = 13 ;
		
	private class Card {
		public int faceVal ;  // contains int values 1 - 13
		public int suit ;	  // contains int values 1 - 4 
		public boolean exist ;// shows if the card has been displayed
		
		public Card(int face, int suitNum){
			faceVal = face ;
			suit = suitNum ;
			exist = false ;
		} // end card constructor
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
	
	
	// function: checkExists
	// pre: must pass in Card object
	// post: returns an integer for the card number
	public int checkExists(int hold) {
		while (this.getExist(this.getCard(hold))) 
			 hold = this.draw() ;
		return hold ;
		
	} // end checkExists 
	
	
	// function: display
		// pre: must pass in Card object
		// post: prints the card with suit and face value
	public void display(Card pick) {
		
		System.out.println(this.getFaceVal(pick) + " of " + this.getSuit(pick)); 
		pick.exist = true ;

	} // end display
	
} // end Deck class
