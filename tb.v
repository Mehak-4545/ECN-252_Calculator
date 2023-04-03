//TB
`include "calc.v"


module tb ();
   integer     fd; 
  reg [3:0] a,  b;
  reg [2:0] optr;
  wire [7:0] result;
//   wire sign_flag;
  
  calculator AA (a, b, optr, result);
  
//   always #1 clk = ~clk;
  
  initial begin
    fd = $fopen("vercal.txt", "w");  
    //result =8'b0;
    a = 4'b1000;
    b = 4'b0000;
    optr = 3'b011;
    
    if(optr==3'b001 && (a<b))
        begin
            $monitor ("Result = -%b", result);
            //$fdisplay(fd, result); 
            #5 
            $fwrite(fd, "-%d", result);  
            //$fclose(fd);
        end

    if(optr==3'b011 && b==0)
      begin
        $monitor ("Error: division by zero");
            //$fdisplay(fd, result); 
            #5 
            $fwrite(fd, "Error: division by zero");  
            //$fclose(fd);
      end

    else
        begin
            $monitor ("Result = %b", result);
            //$fdisplay(fd, result); 
            #5 
            $fwrite(fd, "%d", result);  
            //$fclose(fd); 
        end
     
  end
  
  initial begin
  $dumpfile("dump.vcd");
    $dumpvars(0);
end
  
endmodule