import re

def extract_emails(input_filepath, output_filepath):
    # Regex pattern for matching standard email addresses
    email_pattern = r'[a-zA-Z0-9._%+-]+@[a-zA-Z0-9.-]+\.[a-zA-Z]{2,}'
    
    try:
        # File handling: Open and read the input .txt file
        with open(input_filepath, 'r', encoding='utf-8') as file:
            text_content = file.read()
            
        # Use the 're' module to find all matching email strings
        found_emails = re.findall(email_pattern, text_content)
        
        # Remove duplicates by converting to a set, then back to a sorted list
        unique_emails = sorted(list(set(found_emails)))
        
        # File handling: Write the extracted emails to the output file
        with open(output_filepath, 'w', encoding='utf-8') as file:
            for email in unique_emails:
                file.write(email + '\n')
                
        print(f"Success! {len(unique_emails)} unique email(s) extracted and saved to '{output_filepath}'.")
        
    except FileNotFoundError:
        print(f"Error: The file '{input_filepath}' was not found. Please check the path and try again.")
    except Exception as e:
        print(f"An unexpected error occurred: {e}")

if __name__ == "__main__":
    # Example usage (ensure 'source_text.txt' exists in your directory before running)
    extract_emails('source_text.txt', 'emails_output.txt')