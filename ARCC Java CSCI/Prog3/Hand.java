//******************************************************************************
// Chris Dang			CSCI Java 1125
// Hand Class
//******************************************************************************
import java.lang.* ;
import javax.swing.* ;

public class Hand extends Deck{
	
	// Payout values for winning hands
			final int NO_PAIR = 0 ;
			final int PAIR = 1 ;
			final int TWO_PAIR = 2 ;
			final int THREE_KIND = 3 ;
			final int STRAIGHT = 4 ;
			final int FLUSH = 5 ;
			final int FULL_HOUSE = 6 ;
			final int FOUR_KIND = 25 ;
			final int STRAIGHT_FLUSH = 50 ;
			final int ROYAL_FLUSH = 250 ;
			
			final int HAND = 5 ;
	
private Card[] Hand ;
	
// constructs a sample hand to start
// hand consists of a card array of size 5
	public Hand(){
		Hand = new Card[HAND] ;
		for (int i = 0 ; i < HAND; i++) {
			Hand[i] = new Card(1, 1);
		} // end for
	} // end hand constructor
	
	public void display() {
		for (int i = 0; i < HAND; i++)
		System.out.println(this.getFaceVal(Hand[i]) + " of " + this.getSuit(Hand[i])); 
	}
	
	// sorts hand
	public Hand sortHand() {
		Card temp ;
		for (int i = 0; i < HAND - 1; i++){
			for (int j = 1; j < HAND - i; j++) {
				if (Hand[j-1].faceVal > Hand[j].faceVal){
					temp = Hand[j-1] ;
					Hand[j-1] = Hand[j] ;
					Hand[j] = temp ;
				}// end if
			}// end for
		}// end for
	    return this ;  
	} // end sortHand
	
	// valueHand
	// pre: none
	// post: will return an integer value for the payout of the hand based on a chart given
	
	public int valueHand() {
		int value = 0 ;
		
		
		// checks for flush
		if(Hand[0].suit == Hand[1].suit && 
		   Hand[1].suit == Hand[2].suit && 
		   Hand[2].suit == Hand[3].suit && 
		   Hand[3].suit == Hand[4].suit) {

			// check for straight flush
			
			int count = 0 ;
			for (int i = 0; i < HAND ; i++) {
				int j = ( i + 1 ) % 5;
				if (Hand[i].faceVal % 13 == (Hand[j].faceVal - 1))
					count++ ; 

			}// end for
			if (count == 4){ // if count == 4, then check for royal flush
				//System.out.println("Count is: " + count) ;
				
				if(Hand[0].faceVal ==  1 && 
				   Hand[1].faceVal == 10 && 
				   Hand[2].faceVal == 11 && 
				   Hand[3].faceVal == 12 && 
				   Hand[4].faceVal == 13)
					return value = ROYAL_FLUSH ;  
				return value = STRAIGHT_FLUSH ;  // else return straight flush
			}
			return value = FLUSH ;  // else return straight flush
			
		} // end if
		
		else {
			// checks for straights
			int count = 0 ;
			for (int i = 0; i < HAND ; i++) {
				int j = ( i + 1 ) % 5;
				if (Hand[i].faceVal % 13 == (Hand[j].faceVal - 1))
					count++ ; 
			} // end for
			if (count == 4) 
				return value = STRAIGHT ;
				
				// check for 4 of a kind
			if  (Hand[0].faceVal == Hand[1].faceVal &&
				 Hand[1].faceVal == Hand[2].faceVal &&
				 Hand[2].faceVal == Hand[3].faceVal 

				 &&
				 
				 Hand[1].faceVal == Hand[2].faceVal &&
				 Hand[2].faceVal == Hand[2].faceVal &&
				 Hand[3].faceVal == Hand[4].faceVal) 
				return FOUR_KIND ;
			
			// check for 3 the 3 combinations of 3 of a kind
			for (int i = 0; i < 3; i++) { // if 3 of a kind is the first 3 cards, middle 3, and last 3
				int j = i ; // used to hold start of the three of a kind
				if (Hand[i].faceVal == Hand[i+1].faceVal &&
					Hand[i+1].faceVal == Hand[i+2].faceVal){
					// check for full house 
					if (j == 2 ) // checks if pair is lower faceVal than 3-of kind
						if (Hand[0].faceVal == Hand[1].faceVal)
							return FULL_HOUSE ;
									
					if (j == 0) // checks if pair is higher faceVal than 3-of kind		
						if (Hand[3].faceVal == Hand[4].faceVal) 
					// check for pair to match with 3 of kind for full house

							return FULL_HOUSE ; 
					return THREE_KIND ;
			}// end for			
				}// end if
				// checks for 4 combinations of a pair
			int pairs = 0 ;
			for (int k = 0; k < 4; k++){
				if (Hand[k].faceVal == Hand[k+1].faceVal)
					pairs++ ; // keeps track of number of pairs in hand
			} // end check-pair for
				if (pairs == 1)
					return PAIR ;
				if (pairs == 2)
					return TWO_PAIR ;

			}// end else
		// if all checks fail, pay out is 0.
		return  NO_PAIR;
	} // end valueHand
	
	// randomHand
	// pre: none
	// post: will return an hand of random cards
	public Hand randomHand() {

		for (int i = 0; i < HAND; i++){
			int hold = this.draw() ;     // card number is initially drawn
			hold = this.checkExists(hold) ;
			Hand[i] = this.getCard(hold) ;

		
		}// end for
		return this ;
	}// end randomHand
	
	
	// swapCard
	// pre: must pass in an integer value for the index in the hand (0 - 4)
	// post: Hand[i] will contain a random card.
	public void swapCard(int i) {
		int hold = this.draw() ;         // draw random nunmber
		hold = this.checkExists(hold) ;  // check to sure number is unique
		Hand[i] = this.getCard(hold) ;   // sets new random card in hand
	} // end swapCard
	
	
	// showCard
	// pre: must pass in an integer value for the index in the hand (0 - 4)
	// post: Will return the label containing the image of card
	public JLabel showCard(int i) {
		int hold = this.getHold(Hand[i]) ;   // get index number of card (0 - 51)
		return handCard(hold) ;				 // return label based on index number
	} // end showCard
	
	
} // end Hand class
