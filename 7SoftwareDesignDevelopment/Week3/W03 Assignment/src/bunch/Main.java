package bunch;

import java.io.IOException;


public class Main {

    public static void main (String[] args) {
        APIConnect getInfo = new APIConnect();
        try {
            getInfo.option();
        }
        catch (IOException ex) {
            System.out.println("Mission Failed, we'll get 'em next time");
        }
    }
}
