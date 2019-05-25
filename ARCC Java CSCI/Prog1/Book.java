
public class Book {

	private String title, author, publisher ;
	private String copyrightDate ;
	
	
	//-Constructor -------------------------------
	public Book(){
		
		title = "n/a" ;
		author = "n/a" ;
		publisher = "n/a" ;
		
		copyrightDate = "01 January 1900" ;
		
	}// end constructor
		
	//-Getters--------------------------------------
	public String getTitle(){
		return title ;
	}
	
	public String getAuthor(){
		return author ;
	}
		
	public String getPublisher(){
		return publisher ;
	}
	
	public String getCopyrightDate(){
		return publisher ;
	}
	
	
	//-Setters--------------------------------------
	public void setTitle(String str){
		title = str ;
	}
	
	public void setAuthor(String str){
		author = str ;
	}
	
	public void setPublisher(String str){
		publisher = str ;
	}
	
	public void setCopyrightDate(String str){
		copyrightDate = str ;
	}
	
	
	public String toString() {
		String str = "         Title: " + title +
					 "\n        Author: " + author +
					 "\n     Publisher: " + publisher +
					 "\nCopyright Date: " + copyrightDate ;
		
		return str ;
		
	}
	
}
