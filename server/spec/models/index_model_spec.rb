require 'rails_helper'

describe "Index" do
	before(:all) do
		@index = Index.new
	end

	describe "initialize" do
		it 'has a client_server' do
			expect(@index.client_server.nil?).to be false
		end

		it 'has an empty hash of signed in users' do
			expect(@index.signed_in_users.empty?).to be true
		end
	end
end