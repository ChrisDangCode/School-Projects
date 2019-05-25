
public class Bookshelf {

	public static void main(String[] args) {
		
		Book sherlockHolmes = new Book() ;
		Book newStuff = new Book() ;
		
		sherlockHolmes.setTitle("Adventures of Sherlock Holmes");
		sherlockHolmes.setAuthor("Sir Arthur Conan Doyle");
		sherlockHolmes.setPublisher("London Publishing");
		sherlockHolmes.setCopyrightDate("18 July 1890");
		
		System.out.println(sherlockHolmes.toString()) ;
		
		System.out.println("\n----------Before Update------------") ;
		System.out.println("    Title: " + newStuff.getTitle()) ;
		System.out.println("   Author: " + newStuff.getAuthor()) ;
		System.out.println("Publisher: " +newStuff.getPublisher()) ;
		System.out.println("Copyright: " +newStuff.getCopyrightDate()) ;
		
		newStuff.setTitle("Java - Software Solutions 8th Editions");
		newStuff.setAuthor("Lewis & Loftus") ;
		newStuff.setPublisher("Pearson Publishing") ;
		newStuff.setCopyrightDate("5 January 2015") ;
		
		System.out.println("\n----------After Update------------") ;
		
		System.out.println(newStuff.toString()) ;
		
	}

}
