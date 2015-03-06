require 'rails_helper'

describe "User" do
	before(:all) do
		User.create!(username: 'test', password: 'password')
	end
	describe 'creation' do
		it 'creates one record' do
			expect(User.count).to eq(1)
		end

		it 'sets the proper username' do
			user = User.first
			expect(user.username).to eq('test')
			expect(user.password).to eq('password')
		end
	end
end