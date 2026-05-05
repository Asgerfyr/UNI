import json
import base64
from datetime import datetime, time
from typing import List

class HeartRateReading:
    def __init__(self, bpm: int, timestamp: datetime):
        self.bpm = bpm
        self.timestamp = timestamp

class Patient:
    def __init__(self, name: str, sleep_time: time, wake_time: time, readings: List[HeartRateReading]):
        self.name = name
        self.sleep_time = sleep_time
        self.wake_time = wake_time
        self.readings = readings

    def is_sleeping(self, timestamp):
        t = timestamp.time()
        if self.sleep_time < self.wake_time:
            return self.sleep_time <= t < self.wake_time
        else:
            return t >= self.sleep_time or t < self.wake_time

    def average_heart_rate(self):
        total = sum(r.bpm for r in self.readings)
        avg = total / (len(self.readings) if self.readings else 1)
        return avg

    def get_max_heart_rate(self):
        return max(r.bpm for r in self.readings)

    def get_min_heart_rate(self):
        return min(r.bpm for r in self.readings)

    def abnormal_readings(self):
        abnormal = []
        for reading in self.readings:
            sleeping = self.is_sleeping(reading.timestamp)
            if sleeping:
                if reading.bpm < 50 or reading.bpm > 90:
                    abnormal.append(reading)
            else:
                if reading.bpm < 60 or reading.bpm > 100:
                    abnormal.append(reading)
        return abnormal

    def report(self):
        print(f"\n--- Health Report for {self.name} ---")
        print(f"Total Readings: {len(self.readings)}")
        print(f"Average Heart Rate: {self.average_heart_rate():.2f} bpm")
        print(f"Max Heart Rate: {self.get_max_heart_rate()} bpm")
        print(f"Min Heart Rate: {self.get_min_heart_rate()} bpm")
        print(f"Abnormal Readings Count: {len(self.abnormal_readings())}")
        print("----------------------------------")


def load_patients_from_json():
    with open(r"C:\Users\Asger\Uni\Github\UNI\2. semester\PROF\debugging\heart-monitor\patients.bin", "rb") as f:
        encoded = f.read()

    decoded_json = base64.b64decode(encoded)
    data = json.loads(decoded_json)

    patients = []
    for entry in data:
        name = entry["Name"]
        sleep_time = datetime.strptime(entry["SleepTime"], "%H:%M:%S").time()
        wake_time = datetime.strptime(entry["WakeTime"], "%H:%M:%S").time()
        readings = [
            HeartRateReading(
                bpm=r["Bpm"],
                timestamp=datetime.fromisoformat(r["Timestamp"])
            )
            for r in entry["Readings"]
        ]
        patients.append(Patient(name, sleep_time, wake_time, readings))

    return patients


if __name__ == "__main__":
    patients = load_patients_from_json()
    
    for p in patients:
        None

    
    patients_with_abnormal_readings = [patient for patient in patients if len(patient.abnormal_readings()) != 0]
    
    for patient in patients_with_abnormal_readings:  
        patient.report()
