create database QuanLyBanHang
use QuanLyBanHang

create table KhachHang(
	MaKhachHang int identity(1,1) primary key,
	TenCongTy nvarchar(100) not null,
	TenGiaoDich nvarchar(100) not null unique,
	DiaChi nvarchar(100) not null,
	Email nvarchar(100) not null unique,
	DienThoai char(10) not null unique,
	Fax char(10) not null unique
);

create table NhaCungCap(
	MaCongTy int identity(1,1) primary key,
	TenCongTy nvarchar(100) not null,
	TenGiaoDich nvarchar(100) not null unique,
	DiaChi nvarchar(100) not null unique,
	DienThoai char(10) not null unique,
	Fax char(10) not null unique,
	Email nvarchar(100) not null unique
);

create table LoaiHang(
	MaLoaiHang int identity(1,1) primary key,
	TenLoaiHang nvarchar(100) not null unique
);

create table MatHang(
	MaHang int identity(1,1) primary key,
	TenHang nvarchar(100) not null unique,
	MaCongTy int,
	MaLoaiHang int,
	SoLuong int check (SoLuong >= 0),
	DonViTinh nvarchar(50) not null,
	GiaHang decimal(10,2) check (GiaHang >= 0),
	foreign key (MaCongTy) references NhaCungCap(MaCongTy),
	foreign key (MaLoaiHang) references LoaiHang(MaLoaiHang)
);

create table NhanVien(
	MaNhanVien int identity(1,1) primary key,
	Ho nvarchar(100) not null,
	Ten nvarchar(100) not null,
	NgaySinh date check (NgaySinh <= getdate()),
	NgayLamViec date check (NgayLamViec <= getdate()),
	DiaChi nvarchar(100) not null unique,
	DienThoai char(10) not null unique,
	LuongCoBan decimal(10,2) check (LuongCoBan >= 0),
	PhuCap decimal(10,2) check (PhuCap >= 0)
);

create table DonDatHang(
	SoHoaDon int identity(1,1) primary key,
	MaKhachHang int not null,
	MaNhanVien int not null,
	NgayDatHang date not null,
	NgayGiaoHang date not null,
	NgayChuyenHang date not null,
	NoiGiaoHang nvarchar(100) not null,
	foreign key (MaKhachHang) references KhachHang(MaKhachHang),
	foreign key (MaNhanVien) references NhanVien(MaNhanVien),
    check (NgayDatHang < getdate()),
	check (NgayGiaoHang > NgayDatHang),
	check (NgayChuyenHang > NgayDatHang and NgayChuyenHang <= NgayGiaoHang)
);

create table ChiTietDatHang(
	SoHoaDon int not null,
	MaHang int not null,
	GiaBan decimal(10,2) check (GiaBan > 0),
	SoLuong int check (SoLuong > 0),
	MucGiamGia decimal(5,2) check (MucGiamGia between 0 and 100 ),
	primary key (SoHoaDon, MaHang),
	foreign key (SoHoaDon) references DonDatHang(SoHoaDon),
	foreign key (MaHang) references MatHang(MaHang)
);



-- Insert dữ liệu vào bảng KhachHang
insert into KhachHang (TenCongTy, TenGiaoDich, DiaChi, Email, DienThoai, Fax)
values 
('Cong Ty A', 'Giao Dich A', 'Dia Chi A', 'emaila@example.com', '0123456789', '0123456789'),
('Cong Ty B', 'Giao Dich B', 'Dia Chi B', 'emailb@example.com', '0987654321', '0987654321');

-- Insert dữ liệu vào bảng NhaCungCap
insert into NhaCungCap (TenCongTy, TenGiaoDich, DiaChi, DienThoai, Fax, Email)
values 
('Nha Cung Cap A', 'Giao Dich A', 'Dia Chi A', '0123456789', '0123456789', 'emaila@example.com'),
('Nha Cung Cap B', 'Giao Dich B', 'Dia Chi B', '0987654321', '0987654321', 'emailb@example.com');

insert into NhaCungCap (TenCongTy, TenGiaoDich, DiaChi, DienThoai, Fax, Email)
values
('VINAMILK', 'Giao Dich C', 'Dia Chi C', '0587654321', '0587654321', 'emailv@example.com');
-- Insert dữ liệu vào bảng LoaiHang
insert into LoaiHang (TenLoaiHang)
values 
('Loai Hang A'),
('Loai Hang B'),
('Loai Hang C');

-- Insert dữ liệu vào bảng MatHang
insert into MatHang (TenHang, MaCongTy, MaLoaiHang, SoLuong, DonViTinh, GiaHang)
values 
('Mat Hang A', 1, 1, 100, 'Cai', 1000.00),
('Mat Hang B', 2, 2, 200, 'Hop', 2000.00),
('Mat Hang C', 1, 3, 300, 'Chiec', 3000.00);

-- Insert dữ liệu vào bảng NhanVien
insert into NhanVien (Ho, Ten, NgaySinh, NgayLamViec, DiaChi, DienThoai, LuongCoBan, PhuCap)
values 
('Nguyen', 'A', '1985-01-01', '2020-01-01', 'Dia Chi A', '0123456789', 5000000.00, 1000000.00),
('Tran', 'B', '1990-01-01', '2021-01-01', 'Dia Chi B', '0987654321', 6000000.00, 2000000.00);

-- Insert dữ liệu vào bảng DonDatHang
insert into DonDatHang (MaKhachHang, MaNhanVien, NgayDatHang, NgayGiaoHang, NgayChuyenHang, NoiGiaoHang)
values 
(1, 1, '2025-03-20', '2025-03-25', '2025-03-22', 'Dia Chi A'),
(2, 2, '2025-03-21', '2025-03-26', '2025-03-23', 'Dia Chi B');

-- Insert dữ liệu vào bảng ChiTietDatHang
insert into ChiTietDatHang (SoHoaDon, MaHang, GiaBan, SoLuong, MucGiamGia)
values 
(1, 1, 1000.00, 10, 0.00),
(1, 2, 2000.00, 20, 5.00),
(2, 3, 3000.00, 30, 10.00);

-- Cau 1: danh sach cac doi tac cung cap hang cho cong ty
select * from NhaCungCap

-- Cau 2: ma hang, ten hang, so luong cac mat hang
select MaHang, TenHang, SoLuong from MatHang

-- Cau 3: ho ten, dia chi va nam bat dau
select Ho + ' ' + Ten AS HoTen, DiaChi, year(NgayLamViec) as NamBatDauLamViec 
from NhanVien;

-- Cau 4: dia chi va dien thoai cua vinamilk
select DiaChi, DienThoai
from NhaCungCap
where TenGiaoDich = 'VINAMILK';

-- Cau 5: Ma va ten cua mat hang co gia lon hon 1000000 va so luong it hon 50
select MaHang, TenHang
from MatHang
where GiaHang > 100000 and SoLuong < 50;

--Cau 6: Moi mat hang trong cong ty do ai cung cap
select MatHang.TenHang, NhaCungCap.TenCongTy as NhaCungCap
from MatHang
join NhaCungCap on MatHang.MaCongTy = NhaCungCap.MaCongTy

--Cau 7: cong ty viet tien cung cap cac mat hang nao
select MatHang.TenHang
from MatHang
join NhaCungCap on MatHang.MaCongTy = NhaCungCap.MaCongTy
where NhaCungCap.TenCongTy = 'Nha Cung Cap A';


--Cau 8: thuc pham do cong ty nao cap
select NhaCungCap.TenCongTy, NhaCungCap.DiaChi
from MatHang
join LoaiHang on MatHang.MaLoaiHang = LoaiHang.MaLoaiHang
join NhaCungCap on MatHang.MaCongTy = NhaCungCap.MaCongTy
where LoaiHang.TenLoaiHang = 'Loai Hang A'

--Cau 9: Tim khach hang (ten giao dich) da dat mua hang sua hop xyz cua cong ty
select KhachHang.TenGiaoDich
from ChiTietDatHang
join DonDatHang on ChiTietDatHang.SoHoaDon = DonDatHang.SoHoaDon
join KhachHang on DonDatHang.MaKhachHang = KhachHang.MaKhachHang
join MatHang on ChiTietDatHang.MaHang = MatHang.MaHang
where MatHang.TenHang = 'Mat Hang A'

--Cau 10: ddon hang so 1 do ai dat, do nhan vien nao lap, thoi gian, dia ddiem giao hang
select KhachHang.TenGiaoDich as KhachDat,
	NhanVien.Ho + ' ' + NhanVien.Ten AS NhanVienLap,
	DonDatHang.NgayGiaoHang,
	DonDatHang.NoiGiaoHang
from DonDatHang
join KhachHang on DonDatHang.MaKhachHang = KhachHang.MaKhachHang
join NhanVien on DonDatHang.MaNhanVien = NhanVien.MaNhanVien
WHERE DonDatHang.SoHoaDon = 1;