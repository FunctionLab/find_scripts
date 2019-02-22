function [ f ] = DataDensityPlot( x, y, levels,limits )
%DATADENSITYPLOT Plot the data density 
%   Makes a contour map of data density
%   x, y - data x and y coordinates
%   levels - number of contours to show
%
% By Malcolm Mclean
%
        map = dataDensity(x, y, 256, 256,limits);
    map = map - min(min(map));
    map = floor(map ./ max(max(map)) * (levels-1));
    f = figure();
    
    image(map);
    colormap(jet(levels));
    set(gca, 'XTick', [1 256]);
    set(gca, 'XTickLabel', limits(1):0.1:limit(2));
    set(gca, 'YTick', [1 256]);
    set(gca, 'YTickLabel', limits(3):1:limits(4));
    uiwait;
end

