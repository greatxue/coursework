package ListDS;
import java.util.List;

public interface ListDS<Item> {
    int size();
    Item get(int i);
    int find(int i);

    void insert(Item x);
    void delete(Item x);
    void makeEmpty(Item x);

    List<Item> toList();
}
