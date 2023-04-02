// Verilog code for calculator : 

module calculator (
  input [3:0] a,
  input [3:0] b,
  input [2:0] optr,
  output reg [7:0] result
//   output reg sign_flag
);

always @(*) begin
  case (optr)
    3'b000: result = a + b; // Addition

    3'b001:
        if (a>=b)
            result = a - b;
        else
            begin
                result = b - a; // Subtraction
            end
            
    3'b010: result = a * b; // Multiplication
    3'b011: result = a / b; // Division
    3'b100: result = a << b; // Left Shift
    3'b101: result = a >> b; // Right Shift
    3'b110: result = a & b; // And
    3'b111: result = a | b; // Or
    default: result = 8'b0;  
  endcase
end

endmodule



//TB

// module tb ();
  
//   reg [3:0] a,  b;
//   reg [2:0] optr;
//   wire [7:0] result;
  
//   calculator AA (a, b, optr, result);
  
// //   always #1 clk = ~clk;
  
//   initial begin
//     a = 4'b0101;
//     b = 4'b0010;
//     optr = 3'b111;
//     $monitor ("Result = %b", result);
    
//   end
  
//   initial begin
//   $dumpfile("dump.vcd");
//     $dumpvars(0);
// end
  
// endmodule