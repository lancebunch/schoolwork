package bunch;

public class WeakPasswordException extends Exception{
        public WeakPasswordException() {
           System.out.println("Password must contain at least 8 characters and at least 1 number.");
        }
}
