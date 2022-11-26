#include<bits/stdc++.h>

using namespace std;
/**
    CartItem is a class for storing the item details with following parameters: 
    @param : productName, untiPrice, gst, quantity
    with getter functions and a setter constructor
*/
class CartItem {
    private: 
        string productName;
        int unitPrice;
        float gst;
        int quantity;

    public:
        CartItem(string productName, int unitPrice, float gst, int quantity) {
            this->productName=productName;
            this->unitPrice=unitPrice;
            this->gst=gst;
            this->quantity=quantity;
        }

        string getProductName() {
            return this->productName;
        }

        int getUnitPrice() {
            if(unitPrice>=500) unitPrice=95*1.0*unitPrice/100;
            return this->unitPrice;
        }

        float getGST() {
            return this->gst;
        }

        int getQuantity() {
            return this->quantity;
        }
};

/**
    ShoppingCart contains business logic of the program.
    with multiple functions as follow's:
        addItem(), productWithMaxGST(), totalAmount()
*/

class ShoppingCart {
    private : 
        vector<CartItem> cartItem;

    public : 
        void addItem(CartItem newData) {
            this->cartItem.push_back(newData);
        } 

        string productWithMaxGST() {
            map<string,float> mp;
            for(auto i: this->cartItem) {
                float gstOn1=i.getGST()*i.getUnitPrice()*1.0/100;
                float value=gstOn1*i.getQuantity();
                mp[i.getProductName()]=value;
            }
            string ans="";
            float maxGST=0;
            for(auto i: mp) {
                if(i.second>=maxGST) ans=i.first;
            }
            return ans;
        }

        double totalAmount() {
            double ans=0;
            for(auto i: this->cartItem) {
                double valueOF1=i.getUnitPrice()*1.0;
                double gstVal=(i.getGST()*valueOF1*1.0)/100;
                double temp=(valueOF1+gstVal)*i.getQuantity();
                ans+=temp;
            }
            return ans;
        }
};

int main() {
    ShoppingCart myCart;

    CartItem item1 = CartItem("Leather wallet", 1100, 18, 1);
    CartItem item2 = CartItem("Umbrella", 900, 12, 4);
    CartItem item3 = CartItem("Cigarette", 200, 28, 3);
    CartItem item4 = CartItem("Honey", 100, 0, 2);

    myCart.addItem(item1);
    myCart.addItem(item2);
    myCart.addItem(item3);
    myCart.addItem(item4);

    cout<<"Product with maximum GST: "<<myCart.productWithMaxGST()<<"\n";
    cout<<"Total amount to be paid: "<<myCart.totalAmount()<<"\n";

    return 0;
}
