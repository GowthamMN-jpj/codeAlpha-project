def stock_portfolio_tracker():
    # Use a hardcoded dictionary to define stock prices
    stock_prices = {
        "AAPL": 180.0,
        "TSLA": 250.0,
        "GOOG": 140.0,
        "MSFT": 330.0,
        "AMZN": 130.0
    }
    
    portfolio = {}
    print("Welcome to the Stock Portfolio Tracker!")
    print(f"Available stocks for tracking: {', '.join(stock_prices.keys())}")
    
    # User inputs stock names and quantity
    while True:
        stock_name = input("\nEnter stock ticker (or type 'done' to calculate): ").upper()
        
        if stock_name == 'DONE':
            break
            
        if stock_name not in stock_prices:
            print("Stock not found. Please choose from the available list.")
            continue
            
        try:
            quantity = float(input(f"Enter quantity of {stock_name} shares: "))
            if quantity < 0:
                print("Quantity cannot be negative.")
                continue
                
            # Add to portfolio (handles multiple entries for the same stock)
            portfolio[stock_name] = portfolio.get(stock_name, 0) + quantity
            
        except ValueError:
            print("Invalid input. Please enter a numerical quantity.")
            
    # Calculate total investment
    total_investment = 0.0
    summary_lines = ["\n--- Portfolio Summary ---"]
    
    for ticker, qty in portfolio.items():
        price = stock_prices[ticker]
        value = qty * price
        total_investment += value
        summary_lines.append(f"{ticker}: {qty} shares @ ${price:.2f} = ${value:.2f}")
        
    # Display total investment value
    summary_lines.append(f"\nTotal Investment Value: ${total_investment:.2f}")
    
    summary_text = "\n".join(summary_lines)
    print(summary_text)
    
    # Optionally save the result in a .txt file
    save_file = input("\nWould you like to save this summary to a .txt file? (y/n): ").lower()
    if save_file == 'y':
        filename = "portfolio_summary.txt"
        try:
            with open(filename, "w") as file:
                file.write(summary_text)
            print(f"Portfolio successfully saved to {filename}")
        except Exception as e:
            print(f"An error occurred while saving the file: {e}")

if __name__ == "__main__":
    stock_portfolio_tracker()