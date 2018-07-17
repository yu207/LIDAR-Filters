clc, clear, close all

% Simulate a LIDAR scan distributed in a sinosoidal fashion
N = 1000;
num_points = 1:1:N;
A = 150; B = 250;
T_total = 40;
for t=1:1:T_total
    scan(t,:) = awgn(A*sin(num_points*2*pi/(N/2))+B,10,'measured');
    ubound(t,:) = 500*ones(1,N);
    lbound(t,:) = 0.03*ones(1,N);
end

csvwrite('LIDAR_data.csv',scan)
% A=[0 1 2 1 3;1 5 7 1 3;2 3 4 1 0;3 3 3 1 3;10 2 4 0 0];
% csvwrite('LIDAR_data.csv',A)
% 
% figure(1)
% plot(num_points,scan)
% 
% for n=1:1:N
%    tmf_scan(:,n)=movmedian(scan(:,n),[4 0]); 
% end
% 
% figure(2)
% plot(num_points,tmf_scan);