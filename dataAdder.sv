module dataAdder(
    input logic signed [15:0] data1In,
    input logic signed [15:0] data2In,
    output logic signed [15:0] dataOutEv,
    output logic signed [15:0] dataOutOdd
);
    logic signed [16:0] sum, diff;
  always_comb begin
      sum  = 17'(data1In) + 17'(data2In);
      diff = 17'(data1In) - 17'(data2In);
      dataOutEv  = sum[16:1];
      dataOutOdd = diff[16:1];
  end
endmodule

