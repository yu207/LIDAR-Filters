clc, clear, close all

N = 1000;
A = 150; B = 250;
T_total = 40;
num_points = 1:1:N;
ubound = 500*ones(1,N);
lbound = 0.03*ones(1,N);
scan=csvread('LIDAR_data.csv');
rf_result=csvread('rf_result.csv');
rf_result=rf_result(:,1:N);
tmf_result=csvread('tmf_result.csv');
tmf_result=tmf_result(:,1:N);
rf_tmf_result=csvread('rf_tmf_result.csv');
rf_tmf_result=rf_tmf_result(:,1:N);

figure(1)
for t=1:1:T_total
    plot(num_points,scan(t,:),'b',num_points,ubound,'k',num_points,lbound,'k')
    xlim([0 N]), ylim([-200 700])
    text(10,650,sprintf('t=%u',t))
    text(5,-25,'range-min=0.03')
    text(5,525,'range-max=500')
    title('LIDAR reading over 40s')
    legend('LIDAR reading')
    ylabel('output'),xlabel('sample')
    f = getframe(gcf);
    [imind,cm] = rgb2ind(f.cdata,256);
    if t==1
        imwrite(imind,cm,'LIDAR_data.gif','DelayTime',0,'LoopCount',inf);
    else
        imwrite(imind,cm,'LIDAR_data.gif','WriteMode','append','DelayTime',0);
    end
end

figure(2)
for t=1:1:T_total
    plot(num_points,scan(t,:),'b',num_points,rf_result(t,:),'g',num_points,ubound,'k',num_points,lbound,'k')
    xlim([0 N]), ylim([-200 700])
    text(10,650,sprintf('t=%u',t))
    text(5,-25,'range-min=0.03')
    text(5,525,'range-max=500')
    title('RF filtered LIDAR reading over 40s')
    legend('LIDAR reading','RF filtered LIDAR reading')
    ylabel('output'),xlabel('sample')
    f = getframe(gcf);
    [imind,cm] = rgb2ind(f.cdata,256);
    if t==1
        imwrite(imind,cm,'rf_result.gif','DelayTime',0,'LoopCount',inf);
    else
        imwrite(imind,cm,'rf_result.gif','WriteMode','append','DelayTime',0);
    end
end

figure(3)
for t=1:1:T_total
    plot(num_points,scan(t,:),'b',num_points,tmf_result(t,:),'r',num_points,ubound,'k',num_points,lbound,'k')
    xlim([0 N]), ylim([-200 700])
    text(10,650,sprintf('t=%u',t))
    text(5,-25,'range-min=0.03')
    text(5,525,'range-max=500')
    title('TMF filtered LIDAR reading over 40s')
    legend('LIDAR reading','TMF filtered LIDAR reading')
    ylabel('output'),xlabel('sample')
    f = getframe(gcf);
    [imind,cm] = rgb2ind(f.cdata,256);
    if t==1
        imwrite(imind,cm,'tmf_result.gif','DelayTime',0,'LoopCount',inf);
    else
        imwrite(imind,cm,'tmf_result.gif','WriteMode','append','DelayTime',0);
    end
end