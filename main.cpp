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

class Workday : public MobileAlertState {
public:
	void alert(AlertStateContext *ctx) {
		cout << "Ring Ring Ring\n";
	}
	void alertType() {
		cout << "Workday: Incoming Call\n";
	}
};

class Evening : public MobileAlertState {
public:
	void alert(AlertStateContext *ctx) {
		cout << "Buzz Buzz\n";
	}
	void alertType() {
		cout << "Evening: Incoming call\n";
	}
};

class Night : public MobileAlertState {
public:
	void alert(AlertStateContext *ctx) {
		cout << "silent silent silent\n";
	}
	void alertType() {
		cout << "Night: Incoming call\n";
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
  MobileAlertState* work = new Workday;
	AlertStateContext *stateContext = new AlertStateContext(work);
	stateContext->getState()->alertType();
	stateContext->alert();
	stateContext->alert();
  MobileAlertState* eve = new Evening;
	stateContext->setState(eve);
	stateContext->getState()->alertType();
	stateContext->alert();
  stateContext->alert();
  MobileAlertState* night = new Night;
  stateContext->setState(night);
	stateContext->getState()->alertType();
	stateContext->alert();
  stateContext->alert();

  
  
}
