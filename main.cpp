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

class Vibration : public MobileAlertState {
public:
	void alert(AlertStateContext *ctx) {
		cout << "vibration...\n";
	}
	void alertType() {
		cout << "Set to Vibration Type\n";
	}
};

class Silent : public MobileAlertState {
public:
	void alert(AlertStateContext *ctx) {
		cout << "silent...\n";
	}
	void alertType() {
		cout << "Set to Silent Type\n";
	}
};

class Ringer : public MobileAlertState {
public:
	void alert(AlertStateContext *ctx) {
		cout << "ring ring ring...\n";
	}
	void alertType() {
		cout << "Set to Ringer Type\n";
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
  MobileAlertState* vibrate = new Vibration;
	AlertStateContext *stateContext = new AlertStateContext(vibrate);
	stateContext->getState()->alertType();
	stateContext->alert();
	stateContext->alert();
  MobileAlertState* silent = new Silent;
	stateContext->setState(silent);
	stateContext->getState()->alertType();
	stateContext->alert();
	stateContext->alert();
	stateContext->alert();
  MobileAlertState* ringer = new Ringer;
  stateContext->setState(ringer);
	stateContext->getState()->alertType();
	stateContext->alert();
	stateContext->alert();
	stateContext->alert();
  stateContext->setState(silent);
	stateContext->getState()->alertType();
	stateContext->alert();
	stateContext->alert();
	stateContext->alert();
  delete silent;
  stateContext->setState(vibrate);
	stateContext->getState()->alertType();
	stateContext->alert();
	stateContext->alert();
	stateContext->alert();
  delete vibrate;
}
