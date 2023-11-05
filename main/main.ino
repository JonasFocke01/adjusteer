#define SAMPLE_SIZE 100
#define MILLIS_ALLOWED 10000 // The device should "beep" after this time

#define trigPin 11
#define echoPin 12

long duration, cm;

int samples[SAMPLE_SIZE] = {0};
int previous_median = 0;
unsigned long previous_median_timestamp = millis();

void setup() {
    // TODO: Remove serial
    Serial.begin (115200);
    pinMode(trigPin, OUTPUT);
    pinMode(echoPin, INPUT);
}

void loop() {
    int new_sample = fetch_new_sample();
    append_new_sample(new_sample);
    int median = calculate_median();
    int should_beep = check_against_old_median(median);
    if (should_beep) {
        beep();
    }
    debug_print_samples();
    delay(250);
}

int fetch_new_sample(){
    digitalWrite(trigPin, LOW);
    delayMicroseconds(5);
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);

    pinMode(echoPin, INPUT);
    duration = pulseIn(echoPin, HIGH);

    return (duration/2) / 29.1; // in cm
}

void append_new_sample(int sample) {
    for(int i = 0; i < SAMPLE_SIZE - 1; i++){
        samples[i] = samples[i + 1];
    }
    samples[SAMPLE_SIZE - 1] = sample;
}

// TODO: get rid of this
void debug_print_samples(){
    for (int i = 0; i < SAMPLE_SIZE; i++){
        Serial.print(samples[i]);
    }
    Serial.print(check_against_old_median(calculate_median()) ? "BEEEEP" : "nothing");
    Serial.println("\n");
}

int calculate_median() {
    int sum = 0;
    for (int i = 0; i < SAMPLE_SIZE; i++){
        sum += samples[i];
    }
    return sum / SAMPLE_SIZE;
}

bool check_against_old_median(int current_median){
    if (current_median == previous_median) {
        if (millis() > previous_median_timestamp + MILLIS_ALLOWED) {
            return true;
        } else {
            return false;
        }
    } else {
        previous_median = current_median;
        previous_median_timestamp = millis();
    }
    return false;
}

void beep(){
    // TODO
}
