//3.WAP for implementation of SIP Algorithm in C++.
#include <iostream>
#include <string>

using namespace std;

class SIP {
public:
  SIP() {}

  void sendInvite(string callee) {
    cout << "Sending INVITE to " << callee << endl;
  }

  void receiveInvite(string caller) {
    cout << "Received INVITE from " << caller << endl;
  }

  void sendOK(string callee) {
    cout << "Sending OK to " << callee << endl;
  }

  void receiveOK(string caller) {
    cout << "Received OK from " << caller << endl;
  }

  void sendBye(string callee) {
    cout << "Sending BYE to " << callee << endl;
  }

  void receiveBye(string caller) {
    cout << "Received BYE from " << caller << endl;
  }
};

int main() {
  SIP sip;

  sip.sendInvite("callee");
  sip.receiveInvite("caller");
  sip.sendOK("callee");
  sip.receiveOK("caller");
  sip.sendBye("callee");
  sip.receiveBye("caller");

  return 0;
}