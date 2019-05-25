//-DrawFive.java----------------------------------------------------------------
// 		Programmer: Chris Dang		Class: CSCI 1125 Spring 2015
// 		Program will draw and display 5 unique cards
//------------------------------------------------------------------------------
public class DrawFive {
	
	public static void main(String[] args) {
		
		final int hand = 5 ;
	
		Deck bikeDeck = new Deck() ;
		
		for (int i = 0; i < hand; i ++) {
			
			int hold = bikeDeck.draw() ;     // card number is initially drawn
			hold = bikeDeck.checkExists(hold) ;// if the card number has been
			bikeDeck.display(bikeDeck.getCard(hold));//drawn, then the number
												// is redrawn until a number 
		} // end for					   that has not been drawn is generated
	} // end static void main
}	// end Draw Five driver
