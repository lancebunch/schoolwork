package bunch;

public class Lodging implements Expense {

    Destination _dest;
    int _totalNights;

    /**
     * @param dest Where we'll be going on vacation.
     * @param nights How long we'll be staying there.
     */
    public Lodging(Destination dest, int nights) {
        _dest = dest;
        _totalNights = nights;
    }

    /**
     * @return The total cost of lodging at our destination.
     */
    public float getCost() {
        switch (_dest) {
            case Mexico:
                return 100.00f * _totalNights;
            case Europe:
                return (200.00f * _totalNights) * 1.10f;
            case Japan:
                return (300.00f * _totalNights) * 1.30f;
            default:
                return 0.0f;
        }
    }
}
