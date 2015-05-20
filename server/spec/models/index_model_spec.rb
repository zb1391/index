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

    it 'listens for clients on the specified port' do
      expect(@index.client_server.is_listening).to be true
    end

    it 'shares the same signed_in_users hash with the client server' do
      @index.signed_in_users[:test] = 1
      expect(@index.client_server.signed_in_users[:test]).to eq(1)
    end
  end
end
