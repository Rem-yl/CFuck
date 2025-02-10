import fitz
import argparse


if __name__ == "__main__":
    parser = argparse.ArgumentParser()
    parser.add_argument("-i", "--input", type=str, help="Input file")
    parser.add_argument("-o", "--output", type=str, help="Output file")
    parser.add_argument("-s", "--start", type=int, help="Start page")
    parser.add_argument("-e", "--end", type=int, help="End page")
    args = parser.parse_args()

    doc = fitz.open(args.input)
    new_pdf = fitz.open()
    new_pdf.insert_pdf(doc, from_page=args.start, to_page=args.end)
    new_pdf.save(args.output)
    new_pdf.close()
    print("Split Pdf done.")
