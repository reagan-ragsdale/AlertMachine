#include <iostream>

using namespace std;

class MobileAlertState;
class AlertStateContext;
class Vibration;
class Silent;

class MobileAlertState {
public:
	virtual void alert(AlertStateContext *ctx) = 0;
	virtual void alertType() = 0;

  virtual ~MobileAlertState() {}
};

class Call : public MobileAlertState {
public:
	void alert(AlertStateContext *ctx) {
		cout << "Annoying Samsung theme ringtone\n";
	}
	void alertType() {
		cout << "Incoming Call\n";
	}
};

class Text : public MobileAlertState {
public:
	void alert(AlertStateContext *ctx) {
		cout << "Buzz Buzz\n";
	}
	void alertType() {
		cout << "New text Message\n";
	}
};

class Email : public MobileAlertState {
public:
	void alert(AlertStateContext *ctx) {
		cout << "Ding\n";
	}
	void alertType() {
		cout << "New emial\n";
	}
};

class AlertStateContext {
private:
	MobileAlertState *currentState;

public:
	AlertStateContext(MobileAlertState *state) {
		currentState = state;
	}

	void setState(MobileAlertState *state) {
		currentState = state;
	}

	MobileAlertState *getState() {
		return currentState;
	}

	void alert() {
		currentState->alert(this);
	}
};

int main() {
  MobileAlertState* call = new Call;
	AlertStateContext *stateContext = new AlertStateContext(call);
	stateContext->getState()->alertType();
	stateContext->alert();
	stateContext->alert();
  MobileAlertState* text = new Text;
	stateContext->setState(text);
	stateContext->getState()->alertType();
	stateContext->alert();
  MobileAlertState* email = new Email;
  stateContext->setState(email);
	stateContext->getState()->alertType();
	stateContext->alert();

  stateContext->setState(text);
	stateContext->getState()->alertType();
	stateContext->alert();

  delete text;
  stateContext->setState(call);
	stateContext->getState()->alertType();
	stateContext->alert();
	stateContext->alert();
	stateContext->alert();
  delete call;
}
