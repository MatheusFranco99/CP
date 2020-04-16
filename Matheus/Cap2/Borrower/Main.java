import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.text.Collator;
import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.Locale;

public class Main{
        public static void main(String args[]) throws IOException{
                BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
                List<Book> allBooks = new ArrayList<Book>();
                List<Book> shelve = new ArrayList<Book>();
                List<Book> toBeReturned = new ArrayList<Book>();
                String line = "", title = "", author = "", command = "";
                int sep, i, len;
                Book b;
                while(true){
                        line = in.readLine();
                        if(line.compareTo("END")==0)
                                break;
                        sep = line.indexOf('"', 1);
                        title = line.substring(0, sep+1);
                        author = line.substring(sep+2);
                        b = new Book(author,title);
                        shelve.add(b);
                        allBooks.add(b);
                }
                Collections.sort(allBooks);
                while(true){
                        line = in.readLine();
                        if(line.compareTo("END")==0)
                                break;
                        else if(line.compareTo("SHELVE")==0){
                                Collections.sort(toBeReturned);
                                i = 0;
                                len = toBeReturned.size();
                                if(shelve.isEmpty()){
                                        System.out.println("Put "+ toBeReturned.get(i++) +" first");
                                }else{
                                        System.out.println("Put "+ toBeReturned.get(i++) +" after "+ shelve.get(shelve.size()-1)); 
                                }
                                for(;i<len;i++){
                                        System.out.println("Put "+ toBeReturned.get(i) +" after "+ toBeReturned.get(i-1));
                                        i++;
                                }
                                System.out.println("END");
                        }else{
                                sep = line.indexOf(' ');
                                command = line.substring(0,sep);
                                title = line.substring(sep+1);
                                if(command.compareTo("RETURN")==0){
                                        b = getBookByTitle(allBooks,title);
                                        toBeReturned.add(b);
                                }
                                else if(command.compareTo("BORROW")==0){
                                        b = getBookByTitle(allBooks,title);
                                        shelve.remove(shelve.indexOf(b));
                                }
                        }
                }
                in.close();
        }
        
        public static Book getBookByTitle(List<Book> lst, String title){
                for(Book b : lst){
                        if(b.title().compareTo(title)==0) return b;
                }
                return null;
        }
}

class Book implements Comparable<Book>{
        private String _author = "";
        private String _title = "";
        public Book(String author,String title){
                _author = author;
                _title = title;
        }
        public String author(){return _author;}
        public String title(){return _title;}
        @Override
        public int compareTo(Book b){
                int r = Collator.getInstance(Locale.getDefault()).compare(_author, b.author());
                if(r!= 0) return r;
                return Collator.getInstance(Locale.getDefault()).compare(_title, b.title());
        }
        @Override
        public String toString(){
                return _title;
        }
}