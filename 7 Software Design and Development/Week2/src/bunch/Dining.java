package bunch;

public class Dining implements Expense {

    Destination _dest;
    int _totalNights;

    /**
     * @param dest Where we'll be going on vacation.
     * @param nights How long we'll be staying there.
     */
    public Dining(Destination dest, int nights) {
        _dest = dest;
        _totalNights = nights;
    }

    /**
     * @return The total cost of dining at our destination.
     */
    public float getCost() {
        switch (_dest) {
            case Mexico:
                return 10.00f * _totalNights;
            case Europe:
                return 20.00f * _totalNights;
            case Japan:
                return 30.00f * _totalNights;
            default:
                return 0.0f;
        }
    }
}
