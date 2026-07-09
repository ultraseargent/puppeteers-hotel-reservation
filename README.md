# puppeteers-hotel-reservation


# Puppeteers Hotel Reservation System

A console-based hotel room booking and management system built in C++. This project simulates a complete hotel check-in process with pricing, discounts, VAT calculation, and transaction summaries.

## Features

- **Room Types**: Regular, Deluxe, and VIP with different pricing tiers
- **Flexible Stay Duration**: 6 hours, 12 hours, or 24 hours
- **Dynamic Pricing** based on room type and hours of stay
- **Discount System**:
  - 20% discount for Senior Citizens (60+)
  - 20% discount for Persons with Disability
  - Special consideration for guests with children below 3 years old
- **VAT Calculation** (12%)
- **Payment Processing** with change calculation
- **Input Validation** (name, age, payment amount)
- **Room Availability Tracking**
- **Transaction Summary** with full details after booking
- **Search Room Details** functionality

## Tech Stack

- **Language**: C++
- **Paradigm**: Structured Programming
- **Input/Output**: Console-based interface

## How to Compile and Run

### Requirements
- g++ compiler (MinGW on Windows or GCC on Linux/Mac)

### Compilation

```bash
g++ Hotelreservation.cpp -o hotel
