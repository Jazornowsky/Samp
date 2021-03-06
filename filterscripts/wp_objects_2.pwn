#include <a_samp>
#include <streamer>

#define FILTERSCRIPT

public OnFilterScriptInit()
{
	new a[][] =
	{
		"Unarmed (Fist)",
		"Brass K"
	};
	#pragma unused a	
	
	CreateDynamicObject(2395, 1537.65, -1758.85, 32.50,  270.00, 180.00, 180.00, 1);
	CreateDynamicObject(2395, 1541.37, -1761.59, 32.50,  270.00, 180.00, 180.00, 1);
	CreateDynamicObject(2395, 1541.37, -1764.32, 32.50,  270.00, 179.99, 179.99, 1);
	CreateDynamicObject(2395, 1541.37, -1767.06, 32.50,  270.00, 180.00, 180.00, 1);
	CreateDynamicObject(2395, 1541.37, -1758.85, 32.50,  270.00, 180.00, 180.00, 1);
	CreateDynamicObject(2395, 1533.93, -1758.85, 32.50,  270.00, 180.00, 180.00, 1);
	CreateDynamicObject(2395, 1530.20, -1758.85, 32.50,  270.00, 180.00, 180.00, 1);
	CreateDynamicObject(2395, 1537.65, -1761.59, 32.50,  270.00, 180.00, 180.00, 1);
	CreateDynamicObject(2395, 1537.65, -1764.32, 32.50,  270.00, 180.00, 180.00, 1);
	CreateDynamicObject(2395, 1537.65, -1767.06, 32.50,  270.00, 179.99, 179.99, 1);
	CreateDynamicObject(2395, 1533.93, -1761.59, 32.50,  270.00, 180.00, 180.00, 1);
	CreateDynamicObject(2395, 1530.20, -1761.59, 32.50,  270.00, 180.00, 180.00, 1);
	CreateDynamicObject(2395, 1533.93, -1764.32, 32.50,  270.00, 180.00, 180.00, 1);
	CreateDynamicObject(2395, 1530.20, -1764.32, 32.50,  270.00, 180.00, 180.00, 1);
	CreateDynamicObject(2395, 1530.20, -1767.06, 32.50,  270.00, 179.99, 179.99, 1);
	CreateDynamicObject(2395, 1533.93, -1767.06, 32.50,  270.00, 180.00, 180.00, 1);
	CreateDynamicObject(3944, 1530.80, -1765.16, 31.90,  0.00, 0.00, 90.00, 1);
	CreateDynamicObject(3944, 1543.70, -1765.15, 31.90,  0.00, 0.00, 270.00, 1);
	CreateDynamicObject(3944, 1541.90, -1771.30, 31.90,  0.00, 0.00, 180.00, 1);
	CreateDynamicObject(2395, 1541.37, -1772.53, 32.50,  270.00, 180.00, 180.00, 1);
	CreateDynamicObject(2395, 1537.65, -1769.79, 32.50,  270.00, 180.00, 180.00, 1);
	CreateDynamicObject(2395, 1533.93, -1769.79, 32.50,  270.00, 180.00, 180.00, 1);
	CreateDynamicObject(2395, 1530.20, -1769.79, 32.50,  270.00, 179.99, 179.99, 1);
	CreateDynamicObject(2395, 1541.37, -1769.79, 32.50,  270.00, 179.99, 179.99, 1);
	CreateDynamicObject(2395, 1537.65, -1772.53, 32.50,  270.00, 180.00, 180.00, 1);
	CreateDynamicObject(2395, 1533.93, -1772.53, 32.50,  270.00, 180.00, 180.00, 1);
	CreateDynamicObject(2395, 1530.20, -1772.53, 32.50,  270.00, 180.00, 180.00, 1);
	CreateDynamicObject(1502, 1529.90, -1772.40, 32.50,  0.00, 0.00, 0.00, 1);
	CreateDynamicObject(1502, 1532.94, -1772.35, 32.50,  0.00, 0.00, 179.99, 1);
	CreateDynamicObject(1649, 1531.50, -1772.36, 36.67,  0.00, 0.00, 179.99, 1);
	CreateDynamicObject(1649, 1531.50, -1772.36, 36.67,  0.00, 0.00, 0.00, 1);
	CreateDynamicObject(3944, 1541.88, -1775.02, 31.90,  0.00, 0.00, 0.00, 1);
	CreateDynamicObject(3944, 1530.80, -1783.25, 31.90,  0.00, 0.00, 90.00, 1);
	CreateDynamicObject(1649, 1545.30, -1756.10, 34.10,  0.00, 0.00, 0.00, 1);
	CreateDynamicObject(1649, 1532.10, -1756.10, 34.10,  0.00, 0.00, 0.00, 1);
	CreateDynamicObject(1649, 1536.50, -1756.10, 34.10,  0.00, 0.00, 0.00, 1);
	CreateDynamicObject(1649, 1540.90, -1756.10, 34.10,  0.00, 0.00, 0.00, 1);
	CreateDynamicObject(3944, 1549.90, -1783.21, 31.90,  0.00, 0.00, 270.00, 1);
	CreateDynamicObject(2395, 1530.20, -1775.27, 32.50,  270.00, 180.00, 180.00, 1);
	CreateDynamicObject(2395, 1533.93, -1775.27, 32.50,  270.00, 180.00, 180.00, 1);
	CreateDynamicObject(2395, 1537.65, -1775.27, 32.50,  270.00, 180.00, 180.00, 1);
	CreateDynamicObject(2395, 1545.10, -1775.27, 32.50,  270.00, 180.00, 180.00, 1);
	CreateDynamicObject(2395, 1541.37, -1775.27, 32.50,  270.00, 180.00, 180.00, 1);
	CreateDynamicObject(2395, 1548.83, -1775.27, 32.50,  270.00, 180.00, 180.00, 1);
	CreateDynamicObject(2395, 1548.83, -1778.01, 32.50,  270.00, 180.00, 180.00, 1);
	CreateDynamicObject(2395, 1548.83, -1780.75, 32.50,  270.00, 180.00, 180.00, 1);
	CreateDynamicObject(2395, 1548.83, -1783.49, 32.50,  270.00, 180.00, 180.00, 1);
	CreateDynamicObject(2395, 1548.83, -1786.23, 32.50,  270.00, 180.00, 180.00, 1);
	CreateDynamicObject(2395, 1548.83, -1788.97, 32.50,  270.00, 179.99, 179.99, 1);
	CreateDynamicObject(2395, 1548.83, -1791.71, 32.50,  270.00, 180.00, 180.00, 1);
	CreateDynamicObject(2395, 1545.10, -1778.01, 32.50,  270.00, 180.00, 180.00, 1);
	CreateDynamicObject(2395, 1541.37, -1778.01, 32.50,  270.00, 180.00, 180.00, 1);
	CreateDynamicObject(2395, 1537.65, -1778.01, 32.50,  270.00, 180.00, 180.00, 1);
	CreateDynamicObject(2395, 1533.93, -1778.01, 32.50,  270.00, 180.00, 180.00, 1);
	CreateDynamicObject(2395, 1530.20, -1778.01, 32.50,  270.00, 180.00, 180.00, 1);
	CreateDynamicObject(2395, 1545.10, -1780.75, 32.50,  270.00, 180.00, 180.00, 1);
	CreateDynamicObject(2395, 1541.37, -1780.75, 32.50,  270.00, 180.00, 180.00, 1);
	CreateDynamicObject(2395, 1537.65, -1780.75, 32.50,  270.00, 180.00, 180.00, 1);
	CreateDynamicObject(2395, 1533.93, -1780.75, 32.50,  270.00, 180.00, 180.00, 1);
	CreateDynamicObject(2395, 1530.20, -1780.75, 32.50,  270.00, 180.00, 180.00, 1);
	CreateDynamicObject(2395, 1545.10, -1783.49, 32.50,  270.00, 180.00, 180.00, 1);
	CreateDynamicObject(2395, 1541.37, -1783.49, 32.50,  270.00, 180.00, 180.00, 1);
	CreateDynamicObject(2395, 1537.65, -1783.49, 32.50,  270.00, 180.00, 180.00, 1);
	CreateDynamicObject(2395, 1533.93, -1783.49, 32.50,  270.00, 180.00, 180.00, 1);
	CreateDynamicObject(2395, 1530.20, -1783.49, 32.50,  270.00, 180.00, 180.00, 1);
	CreateDynamicObject(2395, 1545.10, -1786.23, 32.50,  270.00, 180.00, 180.00, 1);
	CreateDynamicObject(2395, 1541.37, -1786.23, 32.50,  270.00, 180.00, 180.00, 1);
	CreateDynamicObject(2395, 1537.65, -1786.23, 32.50,  270.00, 180.00, 180.00, 1);
	CreateDynamicObject(2395, 1533.93, -1786.23, 32.50,  270.00, 180.00, 180.00, 1);
	CreateDynamicObject(2395, 1530.20, -1786.23, 32.50,  270.00, 180.00, 180.00, 1);
	CreateDynamicObject(2395, 1545.10, -1788.97, 32.50,  270.00, 180.00, 180.00, 1);
	CreateDynamicObject(2395, 1541.37, -1788.97, 32.50,  270.00, 180.00, 180.00, 1);
	CreateDynamicObject(2395, 1537.65, -1788.97, 32.50,  270.00, 180.00, 180.00, 1);
	CreateDynamicObject(2395, 1533.93, -1788.97, 32.50,  270.00, 180.00, 180.00, 1);
	CreateDynamicObject(2395, 1530.20, -1788.97, 32.50,  270.00, 180.00, 180.00, 1);
	CreateDynamicObject(2395, 1545.10, -1791.71, 32.50,  270.00, 180.00, 180.00, 1);
	CreateDynamicObject(2395, 1541.37, -1791.71, 32.50,  270.00, 180.00, 180.00, 1);
	CreateDynamicObject(2395, 1537.65, -1791.71, 32.50,  270.00, 179.99, 179.99, 1);
	CreateDynamicObject(2395, 1533.93, -1791.71, 32.50,  270.00, 180.00, 180.00, 1);
	CreateDynamicObject(2395, 1530.20, -1791.71, 32.50,  270.00, 179.99, 179.99, 1);
	CreateDynamicObject(4718, 1534.60, -1795.67, 84.70,  0.00, 90.00, 89.99, 1);
	CreateDynamicObject(2435, 1544.20, -1768.70, 32.40,  0.00, 0.00, 180.00, 1);
	CreateDynamicObject(2435, 1543.27, -1768.70, 32.40,  0.00, 0.00, 179.99, 1);
	CreateDynamicObject(2435, 1543.27, -1768.70, 32.40,  0.00, 0.00, 179.99, 1);
	CreateDynamicObject(2435, 1542.34, -1768.70, 32.40,  0.00, 0.00, 179.99, 1);
	CreateDynamicObject(2435, 1541.42, -1768.70, 32.40,  0.00, 0.00, 179.99, 1);
	CreateDynamicObject(2435, 1540.49, -1768.70, 32.40,  0.00, 0.00, 179.99, 1);
	CreateDynamicObject(2435, 1539.60, -1768.70, 32.40,  0.00, 0.00, 179.99, 1);
	CreateDynamicObject(2435, 1538.67, -1768.70, 32.40,  0.00, 0.00, 179.99, 1);
	CreateDynamicObject(2435, 1537.74, -1768.70, 32.40,  0.00, 0.00, 179.99, 1);
	CreateDynamicObject(2435, 1536.82, -1768.70, 32.40,  0.00, 0.00, 179.99, 1);
	CreateDynamicObject(2435, 1535.89, -1768.70, 32.40,  0.00, 0.00, 179.99, 1);
	CreateDynamicObject(2435, 1534.96, -1768.70, 32.40,  0.00, 0.00, 179.99, 1);
	CreateDynamicObject(2435, 1534.03, -1768.70, 32.40,  0.00, 0.00, 179.99, 1);
	CreateDynamicObject(2435, 1534.03, -1768.70, 32.40,  0.00, 0.00, 179.99, 1);
	CreateDynamicObject(2434, 1533.10, -1768.70, 32.40,  0.00, 0.00, 180.00, 1);
	CreateDynamicObject(2190, 1534.20, -1768.50, 33.45,  0.00, 0.00, 0.00, 1);
	CreateDynamicObject(3440, 1533.20, -1768.90, 35.70,  0.00, 0.00, 0.00, 1);
	CreateDynamicObject(2190, 1537.00, -1768.50, 33.45,  0.00, 0.00, 0.00, 1);
	CreateDynamicObject(2190, 1540.00, -1768.50, 33.45,  0.00, 0.00, 0.00, 1);
	CreateDynamicObject(2190, 1543.00, -1768.50, 33.45,  0.00, 0.00, 0.00, 1);
	CreateDynamicObject(2202, 1543.80, -1771.70, 32.40,  0.00, 0.00, 180.00, 1);
	CreateDynamicObject(2007, 1541.94, -1771.69, 32.40,  0.00, 0.00, 180.00, 1);
	CreateDynamicObject(2007, 1540.97, -1771.69, 32.40,  0.00, 0.00, 179.99, 1);
	CreateDynamicObject(2007, 1539.99, -1771.69, 32.40,  0.00, 0.00, 179.99, 1);
	CreateDynamicObject(2164, 1538.99, -1772.10, 32.40,  0.00, 0.00, 180.00, 1);
	CreateDynamicObject(1557, 1529.90, -1758.00, 32.29,  0.00, 0.00, 270.00, 1);
	CreateDynamicObject(1557, 1529.90, -1761.00, 32.29,  0.00, 0.00, 90.00, 1);
	CreateDynamicObject(2773, 1541.40, -1767.10, 33.00,  0.00, 0.00, 0.00, 1);
	CreateDynamicObject(2773, 1538.10, -1767.10, 33.00,  0.00, 0.00, 0.00, 1);
	CreateDynamicObject(2773, 1535.30, -1767.10, 33.00,  0.00, 0.00, 0.00, 1);
	CreateDynamicObject(632, 1531.80, -1762.00, 32.87,  0.00, 0.00, 0.00, 1);
	CreateDynamicObject(632, 1531.80, -1756.90, 32.87,  0.00, 0.00, 0.00, 1);
	CreateDynamicObject(1723, 1544.00, -1756.80, 32.40,  0.00, 0.00, 270.00, 1);
	CreateDynamicObject(1723, 1544.00, -1761.00, 32.40,  0.00, 0.00, 270.00, 1);
	CreateDynamicObject(630, 1544.00, -1759.90, 33.50,  0.00, 0.00, 0.00, 1);
	CreateDynamicObject(630, 1544.00, -1759.90, 33.50,  0.00, 0.00, 0.00, 1);
	CreateDynamicObject(2164, 1537.22, -1772.10, 32.40,  0.00, 0.00, 179.99, 1);
	CreateDynamicObject(2167, 1535.45, -1772.20, 32.41,  0.00, 0.00, 180.00, 1);
	CreateDynamicObject(2167, 1534.56, -1772.20, 32.41,  0.00, 0.00, 179.99, 1);
	CreateDynamicObject(1998, 1546.04, -1775.80, 32.50,  0.00, 0.00, 90.00, 1);
	CreateDynamicObject(1998, 1546.04, -1781.00, 32.50,  0.00, 0.00, 90.00, 1);
	CreateDynamicObject(1998, 1546.04, -1786.80, 32.50,  0.00, 0.00, 90.00, 1);
	CreateDynamicObject(1714, 1546.10, -1780.10, 32.50,  0.00, 0.00, 270.00, 1);
	CreateDynamicObject(1714, 1546.20, -1774.80, 32.50,  0.00, 0.00, 270.00, 1);
	CreateDynamicObject(1714, 1546.10, -1785.90, 32.50,  0.00, 0.00, 270.00, 1);
	CreateDynamicObject(2200, 1550.80, -1774.63, 32.42,  0.00, 0.00, 270.00, 1);
	CreateDynamicObject(2200, 1550.60, -1794.20, 32.42,  0.00, 0.00, 270.00, 1);
	CreateDynamicObject(2007, 1550.30, -1779.09, 32.40,  0.00, 0.00, 270.00, 1);
	CreateDynamicObject(2007, 1550.30, -1780.09, 32.40,  0.00, 0.00, 270.00, 1);
	CreateDynamicObject(2007, 1550.30, -1781.09, 32.40,  0.00, 0.00, 270.00, 1);
	CreateDynamicObject(2199, 1550.69, -1782.10, 32.40,  0.00, 0.00, 270.00, 1);
	CreateDynamicObject(2161, 1550.72, -1783.50, 32.44,  0.00, 0.00, 270.00, 1);
	CreateDynamicObject(2161, 1550.72, -1784.83, 32.44,  0.00, 0.00, 270.00, 1);
	CreateDynamicObject(2164, 1550.72, -1786.16, 32.44,  0.00, 0.00, 270.00, 1);
	CreateDynamicObject(2066, 1550.30, -1787.73, 32.40,  0.00, 0.00, 270.00, 1);
	CreateDynamicObject(2066, 1550.30, -1788.31, 32.40,  0.00, 0.00, 270.00, 1);
	CreateDynamicObject(2186, 1550.30, -1789.90, 32.45,  0.00, 0.00, 270.00, 1);
	CreateDynamicObject(2165, 1531.20, -1787.90, 32.40,  0.00, 0.00, 0.00, 1);
	CreateDynamicObject(4718, 1534.60, -1795.67, 84.70,  0.00, 90.00, 90.00, 1);
	CreateDynamicObject(2165, 1536.00, -1787.90, 32.40,  0.00, 0.00, 0.00, 1);
	CreateDynamicObject(1714, 1546.70, -1804.32, 32.50,  0.00, 0.00, 179.99, 1);
	CreateDynamicObject(1714, 1531.70, -1788.90, 32.50,  0.00, 0.00, 179.99, 1);
	CreateDynamicObject(638, 1542.10, -1774.55, 33.10,  0.00, 0.00, 90.00, 1);
	CreateDynamicObject(638, 1534.18, -1774.55, 33.10,  0.00, 0.00, 90.00, 1);
	CreateDynamicObject(638, 1536.86, -1774.55, 33.10,  0.00, 0.00, 90.00, 1);
	CreateDynamicObject(638, 1539.50, -1774.55, 33.10,  0.00, 0.00, 90.00, 1);
	CreateDynamicObject(632, 1535.00, -1787.90, 32.85,  0.00, 0.00, 0.00, 1);
	CreateDynamicObject(14793, 1537.20, -1765.40, 35.60,  0.00, 0.00, 0.00, 1);
	CreateDynamicObject(14793, 1541.30, -1784.10, 35.60,  0.00, 0.00, 0.00, 1);
	CreateDynamicObject(1723, 1543.60, -1794.24, 32.40,  0.00, 0.00, 0.00, 1);
	CreateDynamicObject(1724, 1531.80, -1783.50, 32.40,  0.00, 0.00, 145.00, 1);
	CreateDynamicObject(3944, 1537.80, -1794.53, 31.90,  0.00, 0.00, 0.00, 1);
	CreateDynamicObject(3944, 1537.81, -1790.83, 31.90,  0.00, 0.00, 180.00, 1);
	CreateDynamicObject(3944, 1549.90, -1801.30, 31.90,  0.00, 0.00, 270.00, 1);
	CreateDynamicObject(3944, 1558.70, -1790.83, 31.90,  0.00, 0.00, 180.00, 1);
	CreateDynamicObject(3944, 1558.69, -1794.52, 31.90,  0.00, 0.00, 0.00, 1);
	CreateDynamicObject(3944, 1543.20, -1801.60, 31.90,  0.00, 0.00, 90.00, 1);
	CreateDynamicObject(3944, 1545.60, -1806.00, 31.90,  0.00, 0.00, 180.00, 1);
	CreateDynamicObject(2395, 1545.10, -1791.71, 32.50,  270.00, 180.00, 180.00, 1);
	CreateDynamicObject(2395, 1548.83, -1794.45, 32.50,  270.00, 180.00, 180.00, 1);
	CreateDynamicObject(2395, 1545.10, -1794.45, 32.50,  270.00, 180.00, 180.00, 1);
	CreateDynamicObject(2395, 1541.37, -1794.45, 32.50,  270.00, 180.00, 180.00, 1);
	CreateDynamicObject(2395, 1548.83, -1799.93, 32.50,  270.00, 180.00, 180.00, 1);
	CreateDynamicObject(2395, 1545.10, -1797.19, 32.50,  270.00, 180.00, 180.00, 1);
	CreateDynamicObject(2395, 1541.37, -1797.19, 32.50,  270.00, 180.00, 180.00, 1);
	CreateDynamicObject(2395, 1548.83, -1797.19, 32.50,  270.00, 179.99, 179.99, 1);
	CreateDynamicObject(2395, 1548.83, -1802.67, 32.50,  270.00, 180.00, 180.00, 1);
	CreateDynamicObject(2395, 1548.83, -1805.40, 32.50,  270.00, 180.00, 180.00, 1);
	CreateDynamicObject(2395, 1548.83, -1808.14, 32.50,  270.00, 179.99, 179.99, 1);
	CreateDynamicObject(2395, 1545.10, -1799.93, 32.50,  270.00, 180.00, 180.00, 1);
	CreateDynamicObject(2395, 1541.37, -1799.93, 32.50,  270.00, 180.00, 180.00, 1);
	CreateDynamicObject(2395, 1541.37, -1802.67, 32.50,  270.00, 180.00, 180.00, 1);
	CreateDynamicObject(2395, 1545.10, -1802.67, 32.50,  270.00, 180.00, 180.00, 1);
	CreateDynamicObject(2395, 1545.10, -1805.40, 32.50,  270.00, 180.00, 180.00, 1);
	CreateDynamicObject(2395, 1541.37, -1805.40, 32.50,  270.00, 180.00, 180.00, 1);
	CreateDynamicObject(2395, 1545.10, -1808.14, 32.50,  270.00, 180.00, 180.00, 1);
	CreateDynamicObject(2395, 1541.37, -1808.14, 32.50,  270.00, 179.99, 179.99, 1);
	CreateDynamicObject(1569, 1549.67, -1791.69, 32.40,  0.00, 0.00, 270.00, 1);
	CreateDynamicObject(1569, 1546.83, -1791.69, 32.40,  0.00, 0.00, 270.00, 1);
	CreateDynamicObject(2165, 1546.20, -1803.10, 32.40,  0.00, 0.00, 0.00, 1);
	CreateDynamicObject(1714, 1536.60, -1788.90, 32.50,  0.00, 0.00, 179.99, 1);
	CreateDynamicObject(1723, 1530.50, -1782.00, 32.40,  0.00, 0.00, 90.00, 1);
	CreateDynamicObject(1828, 1544.70, -1795.80, 32.50,  0.00, 0.00, 0.00, 1);
	CreateDynamicObject(1721, 1545.90, -1801.80, 32.50,  0.00, 0.00, 218.00, 1);
	CreateDynamicObject(1649, 1548.60, -1791.70, 36.57,  0.00, 0.00, 179.99, 1);
	CreateDynamicObject(638, 1542.70, -1800.68, 33.10,  0.00, 0.00, 0.00, 1);
	CreateDynamicObject(638, 1542.92, -1791.30, 33.10,  0.00, 0.00, 90.00, 1);
	CreateDynamicObject(638, 1540.24, -1791.30, 33.10,  0.00, 0.00, 90.00, 1);
	CreateDynamicObject(638, 1537.60, -1791.30, 33.10,  0.00, 0.00, 90.00, 1);
	CreateDynamicObject(2007, 1535.70, -1791.20, 32.40,  0.00, 0.00, 180.00, 1);
	CreateDynamicObject(2007, 1533.70, -1791.20, 32.40,  0.00, 0.00, 179.99, 1);
	CreateDynamicObject(2007, 1534.70, -1791.20, 32.40,  0.00, 0.00, 179.99, 1);
	CreateDynamicObject(2332, 1543.30, -1807.00, 33.90,  0.00, 0.00, 180.00, 1);
	CreateDynamicObject(2737, 1530.00, -1764.90, 33.80,  0.00, 0.00, 90.00, 1);
	CreateDynamicObject(2614, 1546.70, -1806.80, 34.60,  0.00, 0.00, 180.00, 1);
	CreateDynamicObject(1649, 1548.60, -1791.70, 36.57,  0.00, 0.00, 0.00, 1);
	CreateDynamicObject(2836, 1546.20, -1802.40, 32.50,  0.00, 0.00, 0.00, 1);
	CreateDynamicObject(2200, 1550.80, -1776.84, 32.42,  0.00, 0.00, 270.00, 1);
	CreateDynamicObject(632, 1550.30, -1805.80, 32.87,  0.00, 0.00, 0.00, 1);
	CreateDynamicObject(638, 1542.70, -1798.00, 33.10,  0.00, 0.00, 0.00, 1);
	
	return 1;
}

public OnFilterScriptExit()
{
	return 1;
}